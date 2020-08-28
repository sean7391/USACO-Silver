// 2016 U.S. Open—Field Reduction: http://usaco.org/index.php?page=viewproblem2&cpid=642

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define trav(a, x) for (auto& a: x)
#define ins insert
#define pq priority_queue
#define sz(x) (int)x.size()
#define rsz resize
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define endl "\n"
#define MAXN 50005

typedef long long ll;
typedef pair<int, int> pii; 

const int dx[4]= {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct cow{
    int x, y, in;
};

int N;
cow cowsx[MAXN], cowsy[MAXN];
set<int> s;
vector<int> v;

bool cmpx(cow a, cow b){
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool cmpy(cow a, cow b){
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

int calcArea(int a, int b, int c){
    int maxX = 0, minX = INT_MAX, maxY = 0, minY = INT_MAX;
    for (int i = 0; i < N; i++){
        if (cowsx[i].in == a || cowsx[i].in == b || cowsx[i].in == c) continue;
        maxX = max(maxX, cowsx[i].x); 
        minX = min(minX, cowsx[i].x); 
        maxY = max(maxY, cowsx[i].y);
        minY = min(minY, cowsx[i].y); 
    }
    
    return (maxX - minX) * (maxY - minY);
}

int main() {
    //setIO("reduce");
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> cowsx[i].x >> cowsx[i].y; cowsx[i].in = i;
        cowsy[i] = cowsx[i];
    }
    sort(cowsx, cowsx + N, cmpx);
    sort(cowsy, cowsy + N, cmpy);
    
    for (int i = 0; i < 3; i++){
        s.ins(cowsx[i].in);
        s.ins(cowsy[i].in);
        s.ins(cowsx[N - 1 - i].in);
        s.ins(cowsy[N - 1 - i].in);
    }
    
    trav(t, s) v.pb(t);
    int ans = INT_MAX;
    for (int i = 0; i < sz(v); i++)
        for (int j = i + 1; j < sz(v); j++)
            for (int k = j + 1; k < sz(v); k++)
                ans = min(ans, calcArea(v[i], v[j], v[k]));
            
    cout << ans << endl;
    return 0;
}

/*
We can remove the three leftmost, rightmost, topmost, and bottommost points,
and try every combination of them, keeping in mind that some points may 
be more than one of the four (so use a set). The answer is just the minimum
of all calculated areas. 
*/
