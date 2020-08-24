// 2019 U.S. Open—Fence Planning: http://www.usaco.org/index.php?page=viewproblem2&cpid=944

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

int N, M;
vector<int> adj[100005];
bool visited[100005];
pii cows[100005];

int minX, minY, maxX, maxY;

void dfs(int n){
    visited[n] = true;
    maxX = max(maxX, cows[n].f);
    minX = min(minX, cows[n].f);
    maxY = max(maxY, cows[n].s);
    minY = min(minY, cows[n].s);
    trav(u, adj[n])
        if (!visited[u])
            dfs(u);
}

int main() {
    //setIO("fenceplan"); 
    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        int a, b; cin >> a >> b;
        cows[i] = {a, b};
    }
        
    for (int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    
    int ans = 1e9;
    for (int i = 1; i <= N; i++){
        if (!visited[i]){
            maxX = cows[i].f; minX = cows[i].f;
            maxY = cows[i].s; minY = cows[i].s;
            dfs(i);
            int perimeter = 2 * ((maxX - minX) + (maxY - minY));
            ans = min(ans, perimeter);
        }
    }
    
    cout << ans << endl;
    return 0;
}

/*
Just DFS through moo networks and keep track of the largest and smallest
x and y coordinates. We can calculate the perimeter easily this way, and
find the smallest perimeter of all moo networks.
*/

