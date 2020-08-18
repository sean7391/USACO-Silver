// January 2018—Mootube: http://www.usaco.org/index.php?page=viewproblem2&cpid=788
 
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
#define MAXN 5005
 
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
 
struct Edge{
    int w, d;
    Edge(int dest, int weight): 
    w(weight), d(dest)
    {
    }
};
 
int N, Q, K, cnt = 0;
vector<Edge> adj[MAXN];
bool visited[MAXN];
 
void dfs(int v){
    visited[v] = true;
    trav(next, adj[v]){
        if (next.w >= K && !visited[next.d]){
            cnt++;
            dfs(next.d);
        }
    }
}
 
int main(){
    setIO("mootube"); 
    cin >> N >> Q;
    for (int i = 0; i < N - 1; i++){
        int p, q, r; cin >> p >> q >> r;
        adj[p].pb(Edge(q, r));
        adj[q].pb(Edge(p, r));
    }
 
    for (int i = 0; i < Q; i++){
        int v; cin >> K >> v; cnt = 0;
        memset(visited, false, sizeof(visited));
        dfs(v);
        cout << cnt << endl;
    }
 
    return 0;
}

/*
This problem is just simple DFS on a weighted graph. Instead of storing destination
like in a normal adjacency matrix, we can store edges instead which also contains 
the weight of the path. Our DFS just has to check each path to see if it is the 
right relevancy.
*/
