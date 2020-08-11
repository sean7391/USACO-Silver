// US Open 2016—Closing the Farm: http://www.usaco.org/index.php?page=viewproblem2&cpid=644

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
bool closed[3001];
vector<int> adj[3001];

void dfs(int node, bool visited[]){
    visited[node] = true;
    trav(next, adj[node]){
        if (!visited[next] && !closed[next])
            dfs(next, visited);
    }
}

bool isConnected(){
    bool visited[3001];
    for (int node = 1; node <= N; node++){
        if (!closed[node]){
            memset(visited, false, sizeof(visited));                
            dfs(node, visited);
            for (int i = 1; i <= N; i++)
                if (!visited[i] && !closed[i])
                    return false;
                    
            return true;
        }
    }
}

int main() {
    //setIO("closing");
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    if (isConnected())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
        
    for (int i = 0; i < N - 1; i++){
        int t; cin >> t;
        closed[t] = true;
        if (isConnected())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}

/*
To check whether the farm is connected at a given state, we can just run dfs from
a barn that is not closed, and if there is at least one unvisited and unclosed barn
at the end, then we know it isn't fully connected.

Thus we just check the connectivity in this fashion after each closing.
*/

