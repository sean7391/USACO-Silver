// December 2017—The Bovine Shuffle: http://www.usaco.org/index.php?page=viewproblem2&cpid=764

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
#define MAXN 100005

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

int pos[MAXN], visited[MAXN];

void dfs(int n){
    set<int> s;
    while (visited[n] == 0){
        visited[n] = 1;
        s.ins(n);
        n = pos[n];
    }
    
    if (s.find(n) != s.end()){
        int cur = n;
        do{
            visited[n] = 2;
            n = pos[n];
        } while(n != cur);
    }
}

int main(){
    //setIO("shuffle");
    int N; cin >> N;
    for (int i = 1; i <= N; i++) cin >> pos[i];
    for (int i = 1; i <= N; i++)
        if (visited[i] == 0)    
            dfs(i);
            
    int ans = 0;
    for (int i = 1; i <= N; i++)
        if (visited[i] == 2)
            ans++;
    
    cout << ans << endl;
    return 0;
}

/*
The key here is to realize that positions within cycles will always have cows
in them. We can used a modified DFS to find cycles—we can keep visiting components,
and use a set to keep track of visited nodes in the component. If we end outside 
of the component, then we know there is no cycle—otherwise, we can go through the
cycle again and mark down the nodes that are in a cycle, and count all such nodes.
*/
