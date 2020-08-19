// February 2018—Rest Stops: http://www.usaco.org/index.php?page=viewproblem2&cpid=810

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
 
int L, N, rF, rB, curMax = 0, pos[1000000], taste[1000000];
bool isMax[1000000];
 
int main() {
    //setIO("reststops"); 
    cin >> L >> N >> rF >> rB;
    for (int i = 0; i < N; i++) cin >> pos[i] >> taste[i];
    for (int i = N - 1; i >= 0; i--){
    	if (taste[i] > curMax){
    	    isMax[i] = true;
    	    curMax = taste[i];
    	}
    }
 
    ll ans = 0;
    int lastStop = 0;
    for (int i = 0; i < N; i++){
    	if (isMax[i]){
    	    int x = pos[i] - lastStop;
    	    ans += ((ll)(x * rF) - (ll)(x * rB)) * taste[i];
    	    lastStop = pos[i];
    	}
    }
 
    cout << ans << endl;
    return 0;
}

/*
This is a simple greedy problem where we have to realize that
we should only stop at stops with a local max of tastiness from the 
right, as when we travel from the left it always makes sense to put
off stopping until we get to a tastier location. Be careful of integer
overflow.
*/
 
