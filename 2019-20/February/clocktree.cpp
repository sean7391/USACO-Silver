// February 2020—Clock Tree: http://www.usaco.org/index.php?page=viewproblem2&cpid=1016

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
#define MAXN 2501

typedef long long ll;
typedef pair<int, int> pii; 

const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int N, ans, a[MAXN], clocks[MAXN];
bool visited[MAXN];
vector<int> adj[MAXN];

void reset(){
    for (int i = 1; i <= N; i++) clocks[i] = a[i];
    memset(visited, 0, sizeof(visited));
}

void dfs(int node, int parent = 0){
    visited[node] = true;
    if (parent > 0){
        clocks[node]++;
        if (clocks[node] > 12) clocks[node] -= 12;
    }
    
    trav(n, adj[node]){
        if (!visited[n])
            dfs(n, node);
    }
    
    if (parent > 0){
        clocks[parent] += 12 - clocks[node] + 1;
        if (clocks[parent] > 12) clocks[parent] -= 12;
    }
}

bool ok(int node){
    reset();
    dfs(node);
    return (clocks[node] == 12 || clocks[node] == 1);
}

int main() {
    //setIO("clocktree"); 
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i < N; i++){
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    for (int i = 1; i <= N; i++)
        if (ok(i))
            ans++;
            
    cout << ans << endl;
    return 0;
}

/*
O(N^2) works here. We can just test every single node to see if it works.
We can DFS from the node and increment everytime we reach a new node.
From the bottom, a child node and parent node can go back and forth until the child
node is 12. We can keep working upwards until we have just the source node left.
If the source node remaining is 12 or 1, then it's a valid starting spot. 
*/

