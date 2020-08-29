// January 2020—Berry Picking: http://usaco.org/index.php?page=viewproblem2&cpid=990

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

int N, K, mod, M = 0, arr[1005];

bool cmp(int a, int b){
    return a % mod > b % mod;
}

int main() {
    //setIO("berries"); 
    cin >> N >> K;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
        M = max(M, arr[i]);
    }
    
    int ans = 0, elsieB = K/2;
    for (int b = 1; b <= M; b++){
        int filled = 0;
        for (int i = 0; i < N; i++) filled += arr[i]/b;
        
        if (filled < elsieB) break;
        if (filled >= K){
            ans = max(ans, b * elsieB);
            continue;
        }
        
        mod = b; sort(arr, arr + N, cmp);
        int cur = (filled - elsieB) * b;
        for (int i = 0; i < N && i + filled < K; i++) cur += arr[i] % b;
        ans = max(ans, cur);
    }
    
    cout << ans << endl;
    return 0;
}

/*
Let's call b the minimum number of berries in any bucket given to Elsie.
Keep track of the max number of berries on any tree, and try all b from 1 
to that number. Let's try to fill as many buckets as we can with this value b.
If at any point our number filled is less than half the buckets, then we can
stop as no more b's will work. If we fill up K or more buckets, then in that 
case it is sure that all of Bessie's buckets are filled with b berries. 
However, if we fill up between K/2 and K buckets, that means that some of Bessie's
buckets are not filled with b berries; in this case, we try to maximally fill them 
up, by sorting the remainder of berries on trees after the initial filling up, and adding
this to the number of berries Bessie currently has (a multiple of b). 
*/

