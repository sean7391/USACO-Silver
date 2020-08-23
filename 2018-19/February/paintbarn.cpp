// February 2019—Painting the Barn: http://www.usaco.org/index.php?page=viewproblem2&cpid=919
 
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
 
int N, K, prefix[1001][1001];
 
int main() {
    //setIO("paintbarn"); 
    cin >> N >> K;
    while (N--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        prefix[a][b]++;
        prefix[a][d]--;
        prefix[c][b]--;
        prefix[c][d]++;
    }
 
    int ans = 0;
    for (int i = 0; i < 1000; i++){
        for (int j = 0; j < 1000; j++){
        	if (i) prefix[i][j] += prefix[i - 1][j];
        	if (j) prefix[i][j] += prefix[i][j - 1];
        	if (i && j) prefix[i][j] -= prefix[i - 1][j - 1];
        	if (prefix[i][j] == K) ans++;
        }
    } 
 
    cout << ans << endl;
    return 0;
}

/*
We can use 1 and -1 to demarcate the bounds 
of each painted rectangle and then use 2D prefix sums.
*/
