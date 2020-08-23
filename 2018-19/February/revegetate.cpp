// February 2018—The Great Revegetation: http://www.usaco.org/index.php?page=viewproblem2&cpid=920

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
 
int N, M, visited[100001];
vector<int> S[100001], D[100001];
bool bad = false;

void dfs(int x, int v){
    visited[x] = v;
    trav(n, S[x]){
        if (visited[n] == 3 - v) bad = true;
        if (!visited[n]) dfs(n, v);
    }
    trav(n, D[x]){
        if (visited[n] == v) bad = true;
        if (!visited[n]) dfs(n, 3 - v);
    }
} 

int main() {
    //setIO("revegetate");
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int a, b; char c; cin >> c >> a >> b;
        if (c == 'C'){
            S[a].pb(b); 
            S[b].pb(a);
        }
        if (c == 'D'){
            D[a].pb(b);
            D[b].pb(a);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= N; i++){
        if (!visited[i]){
            dfs(i, 1);
            ans++;
        }
    }
    
    if (bad) cout << 0;
    else{
        cout << 1;
        for (int i = 0; i < ans; i++) cout << 0;
    }
    
    cout << endl;
    return 0;
}

/*
This is an example of bipartite graphs/graph two-coloring—we want
to find the number of valid components that can be two-colored, and 
then the answer will be 2^(number of components) as each component 
has two possible permutations. 

We can use a modified DFS to find components and if they are valid or not. 
If we come across two nodes connected by an S edge with different types of grass,
then the solution is impossible; likewise, if we come across two nodes connected 
by a D edge with the same types of grass, then the solution is impossible. 
*/



