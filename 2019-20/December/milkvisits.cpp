// December 2019—Milk Visits: http://www.usaco.org/index.php?page=viewproblem2&cpid=968

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

int N, M, num, comp[100005];
char cow[100005];
vector<int> adj[100005];

void dfs(int n){
    if (comp[n]) return;
    comp[n] = num;
    trav(next, adj[n]){
        if (cow[next] == cow[n])
            dfs(next);
    }
}

int main() {
    //setIO("milkvisits"); 
    cin >> N >> M; string s; cin >> s;
    for (int i = 1; i <= N; i++) cow[i] = s[i - 1];
    for (int i = 0; i < N - 1; i++){
        int A, B; cin >> A >> B;
        adj[A].pb(B); adj[B].pb(A);
    }
    
    for (int i = 1; i < N + 1; i++){
        if (!comp[i]){
            num++;
            dfs(i);
        }
    }
    
    for (int i = 0; i < M; i++){
        int A, B; char C; cin >> A >> B >> C;
        if (comp[A] != comp[B] || cow[A] == C) cout << 1;
        else cout << 0;
    }
    
    cout << endl;
    return 0;
}

/*
We can use DFS to generate connected components of the same type of 
cow in our tree; given two endpoints, if there are different components,
then that must mean that both types of cow are present on the route. 
Otherwise, they must be the same component, and thus we have to check 
if either of the endpoints contains the desired cow. 
*/
