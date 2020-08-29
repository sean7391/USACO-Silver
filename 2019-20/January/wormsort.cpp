// January 2020—Wormhole Sort: http://usaco.org/index.php?page=viewproblem2&cpid=992

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

typedef long long ll;
typedef pair<int, int> pii; 

const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int N, M, a, b, w, notOrdered = 0, cows[100005], cmps[100005];
bool ordered[100005];
vector<pii> adj[100005];

void dfs(int n, int width, int cmp){
    cmps[n] = cmp;
    trav(u, adj[n])
        if (cmps[u.first] == 0 && u.s >= width)
            dfs(u.first, width, cmp);
}

int check(int width){
    memset(cmps, 0, sizeof(cmps));
    int cmp = 1;
    for (int i = 1; i <= N; i++){
        if (cmps[i] == 0 && !ordered[i]){
            dfs(i, width, cmp);
            cmp++;
        }
    }
    
    for (int i = 1; i <= N; i++)
        if (!ordered[i] && cmps[i] != cmps[cows[i]])
            return false;
    
    return true;
}

int search(){
    int left = 0, right = 1e9, ans = -1;
    while (left <= right){
        int mid = (left + right)/2;
        if (check(mid)){
            left = mid + 1;
            ans = mid;
        }
        else
            right = mid - 1;
    }
    
    return ans;
}

int main() {
    //setIO("wormsort"); 
    cin >> N >> M;
    for (int i = 1; i <= N; i++){
        cin >> cows[i];
        if (cows[i] != i) notOrdered++;
        else ordered[i] = true;
    }
    if (notOrdered == 0){
        cout << -1 << endl;
        return 0;
    }
    
    for (int i = 0; i < M; i++){
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }
    
    cout << search() << endl;
    return 0;
}

/*
We can binary search for our answer. Whenever we check if a width is valid,
we DFS through the cows that are not where they should be, and mark its component.
Make sure the DFS takes into account the width of the wormhole. 
Then, for every cow, if it is not in the same component as the cow that should be there,
then that width does not work. Note that cows that are ordered correctly are always
going to be in their same component (obviously). 
*/
