// February 2019—Sleepy Cow Herding: http://www.usaco.org/index.php?page=viewproblem2&cpid=918

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

void setIO(string name){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int N, arr[100005];

int solve(){
    if (arr[N - 2] - arr[0] == N - 2 && arr[N - 1] - arr[N - 2] > 2) return 2;
    if (arr[N - 1] - arr[1] == N - 2 && arr[1] - arr[0] > 2) return 2;
    int j = 0, best = 0;
    for (int i = 0; i < N; i++){
        while(arr[j + 1] - arr[i] <= N - 1 && j < N - 1)
            j++;
        
        best = max(best, j - i + 1);
    }
    
    return N - best;
}

int main() {
    //setIO("herding"); 
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    
    int ansMin = solve();
    int ansMax = (arr[N - 1] - arr[0]) - (N - 2) - min(arr[1] - arr[0], arr[N - 1] - arr[N - 2]);
    cout << ansMin << endl << ansMax << endl;
    return 0;
}

// https://www.youtube.com/watch?v=B6PGwBtLQPg
