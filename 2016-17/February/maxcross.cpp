// February 2017—Why Did the Cow Cross the Road II: http://www.usaco.org/index.php?page=viewproblem2&cpid=715

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

int N, K, B;
bool arr[100005];
int dp[100005];

int main() {
    setIO("maxcross"); 
    cin >> N >> K >> B; 
    for (int i = 1; i <= B; i++){
        int t; cin >> t;
        arr[t] = true;
    }
        
    for (int i = 1; i <= N; i++){
        if (arr[i]) dp[i] = dp[i - 1];
        else dp[i] = dp[i - 1] + 1;
    }
    
    int ans = INT_MAX;
    for (int i = 1; i <= N - K + 1; i++){
        int res = dp[i + K - 1] - dp[i - 1];
        res = K - res;
        ans = min(res, ans); 
    }
    
    cout << ans << endl;
}

/*
Simple prefix sums problem. We just keep track of the total number
of operating traffic lights at each location, and then find the 
minimum number of fixed lights to achieve the given interval.
*/
