#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define trav(a, x) for (auto& a: x)
#define endl "\n"
#define MAXN 100001

typedef long long ll;

ll N, ans = 0;
vector<ll> adj[MAXN];
bool visited[MAXN];
int subNodes[MAXN];

int minDouble(int n){
    ll j = 0;
    while (true){
        if (pow(2, j) > n) break;
        j++;
    }
    
    return j;
}

void dfsSub(ll node){
    visited[node] = true;
    trav(u, adj[node]){
        if (!visited[u]){
            subNodes[node]++;
            dfsSub(u);
        }
    }
}

void dfs(ll node){
    visited[node] = true;
    ans += minDouble(subNodes[node]) + subNodes[node];
    trav(u, adj[node]){
        if (!visited[u])
            dfs(u);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (ll i = 0; i < N - 1; i++){
        ll a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    dfsSub(0);
    memset(visited, false, sizeof(visited));
    dfs(0);
    cout << ans << endl;
    return 0;
}

