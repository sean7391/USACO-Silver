// February 2018—Snow Boots: http://www.usaco.org/index.php?page=viewproblem2&cpid=811

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
 
int N, B, ans = INT_MAX;
int arr[250], depth[250], step[250];
bool visited[250][250];
 
void dfs(int i, int b){
	if (visited[i][b]) return;
	visited[i][b] = true;
 
	if (i == N - 1){
		ans = min(ans, b);
		return;
	}
 
	for (int j = i + 1; j < N && j - i <= step[b]; j++)
		if (arr[j] <= depth[b])
			dfs(j, b);
 
	for (int j = b + 1; j < B; j++)
		if (arr[i] <= depth[j])
			dfs(i, j);
}
 
int main() {
    //setIO("snowboots"); 
    cin >> N >> B;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < B; i++) cin >> depth[i] >> step[i];
 
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}

/*
The hard part of this problem is recognizing that you can DFS, but once
you realize it, it becomes quite easy. Since the restraints are pretty low,
we can DFS every possible boot/tile location, and whenever we reach the end,
see what boot we are on and if this is a new minimum.

The way we DFS is, whenever get to a new location, we see if we can step to
any tiles where our current boot will still work, and continue the DFS; after 
that, we try all possible boots at that tile.
*/
