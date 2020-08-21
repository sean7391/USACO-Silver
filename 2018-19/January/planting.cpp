// January 2019—Grass Planting: http://www.usaco.org/index.php?page=viewproblem2&cpid=894

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
#define endl "\n"
#define all(v) v.begin(), v.end()

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

int deg[100005];

int main() {
    //setIO("planting"); 
    int N; cin >> N;
    for (int i = 0; i < N - 1; i++){
        int x, y; cin >> x >> y;
        deg[x]++; deg[y]++;
    }
    
    int ans = 0;
    for (int i = 0; i < 100005; i++)
        ans = max(deg[i], ans);
    
    cout << ans + 1 << endl;
}

/*
Because this is a tree (N nodes, N - 1 pathways), then one 
must recognize that the answer is simply the maximum number
of subtrees + 1, as we each of the subtrees and the root node
with max number of subtrees have to have different colors.
*/
