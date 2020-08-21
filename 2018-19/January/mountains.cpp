// January 2019—Mountain View: http://www.usaco.org/index.php?page=viewproblem2&cpid=896

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
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define endl "\n"

typedef long long ll;
typedef pair<int, int> pii; 

const int dx[4]= {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void setIO(string name){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int N, x, y;
vector<pii> v;

bool isCovered(pii a, pii b){
    int diff = a.f - b.f;
    if (a.s == b.s) return true;
    else if (a.s < b.s)
        if (a.s + diff >= b.s) return true;
    else if (a.s > b.s)
        if (a.s - diff <= b.s) return true;
     
    return false;
}

int main() {
    //setIO("mountains");
    cin >> N;    
    while (N--){
        cin >> x >> y;
        v.pb({y, x});
    }
    sort(all(v));
    
    for (int i = 0; i < sz(v) - 1; i++){
        for (int j = i + 1; j < sz(v); j++){
            if (isCovered(v[j], v[i])){
                v.erase(beg(v) + i);
                i--;
                break;
            }
        }
    }
    
    cout << sz(v) << endl;
    return 0;
}

/*
We sort the mountains by height, and iterate
through all mountains from shortest to second highest
to determine if they are covered by any of the taller
mountains using a function. 
*/
