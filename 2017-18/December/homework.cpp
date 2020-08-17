// December 2017—My Cow Ate My Homework: http://www.usaco.org/index.php?page=viewproblem2&cpid=762

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

ll N, bestNum = 0, bestDen = 1, arr[MAXN], dp[MAXN], mins[MAXN];

int main() {
    //setIO("homework"); 
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
     
    dp[N] = arr[N];
    mins[N] = arr[N];
    for (int i = N - 1; i >= 1; i--){
        mins[i] = min(mins[i + 1], arr[i]);
        dp[i] = dp[i + 1] + arr[i];
    }
    
    for (int k = 1; k <= N - 2; k++){
        if ((dp[k + 1] - mins[k + 1]) * bestDen > bestNum * (N - k - 1)){
            bestNum = dp[k + 1] - mins[k + 1];
            bestDen = N - k - 1;
        }
    }
  
    for (int k = 1; k <= N - 2; k++) 
        if ((dp[k + 1] - mins[k + 1]) * bestDen == bestNum * (N - k - 1))
            cout << k << "\n";
}

/*
We can keep a prefix min from the right to keep track of the min value 
from all indexes to the end. We can also create a a prefix sum from the right,
since Bessie eats from the left. Now, for each index that Bessie can eat up to,
we can use the two created arrays and calculate if this is the largest grade
we can obtain thus far—if so, we keep track of the best numerator and denominator,
and at the end, try all indices and determine if the calculated value matches these.
*/
