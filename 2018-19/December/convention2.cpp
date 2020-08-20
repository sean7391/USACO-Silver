// December 2018—Convention 2: http://www.usaco.org/index.php?page=viewproblem2&cpid=859

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
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define endl "\n"

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii; 

const int dx[4]= {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void setIO(string name){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

struct triple{
    int a, t, index;
};

bool cmp(triple x, triple y){
    return x.a < y.a;
}

int N;
pii original[100005];
triple newest[100005];
pq<int, vector<int>, greater<int>> pq;

int main() {
    //setIO("convention2"); 
    cin >> N; 
    for (int i = 1; i <= N; i++){
        cin >> newest[i].a >> newest[i].t;
        original[i] = {newest[i].a, newest[i].t};
        newest[i].index = i;
    }
    sort(newest + 1, newest + N + 1, cmp);
    
    int ans = -1, i = 1, curEnd = 0;
    while (i <= N){
        if (newest[i].a < curEnd){
            pq.push(newest[i].index);
            i++;
            continue;
        }
        if (!pq.empty()){
            int next = pq.top();
            pq.pop();
            int wait = curEnd - original[next].f;
            ans = max(ans, wait);
            curEnd += original[next].s;
            continue;
        }
        
        curEnd = newest[i].a + newest[i].t;
        i++;
    }
    
    cout << ans << endl;
    return 0;
}

/*
We can simulate the entire process using a priority queue to keep 
track of seniority. We can use two arrays; one with the original order,
and one that we sort which also keeps track of the index of each cow.
*/
