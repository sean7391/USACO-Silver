// 2016 US Open—Diamond Collector: http://www.usaco.org/index.php?page=viewproblem2&cpid=643

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

int N, K;
int arr[500010], L[500010], R[500010];
 
int main() {
    setIO("diamond");
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    sort(arr + 1, arr + N + 1);
    
    int start = 1;
    for (int end = 1; end <= N; end++){
        while(start < end && (arr[end] - arr[start] > K))
            start++;
        
        L[end] = max(L[end - 1], end - start + 1);
    }
    
    start = N;
    for (int end = N; end > 0; end--){
        while (start > end && abs(arr[start] - arr[end]) > K)
            start--;
            
        R[end] = max(R[end + 1], start - end + 1);
    }
    
    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans = max(ans, L[i - 1] + R[i]);
        
    cout << ans << endl;
}

/*
Here, we can use something called a prefix max. We essentially keep track
of the largest number of diamonds we can fit in a box for a certain prefix,
and do this from both the left and the right. At the end, the answer is the 
max sum of two prefixes from both sides; be careful not to double count. 
*/
