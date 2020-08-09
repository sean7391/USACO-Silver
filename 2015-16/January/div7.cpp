//January 2016—Subsequences Summing to Sevens: http://www.usaco.org/index.php?page=viewproblem2&cpid=595

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

int N, first[7], last[7], prefix = 0;

int main() {
    //setIO("div7"); 
    cin >> N;
    for (int i = 0; i < 7; i++) first[i] = 1000001;
    first[0] = 0;
    
    for (int i = 1; i <= N; i++){
        int temp; cin >> temp; prefix += temp;
        prefix %= 7;
        first[prefix] = min(first[prefix], i);
        last[prefix] = i;
    }
    
    int ans = 0;
    for (int i = 0; i < 7; i++)
        if (first[i] <= N)
            ans = max(ans, last[i] - first[i]);
    
    cout << ans << endl;
    return 0;
}

/*
Here, we want to find the sum of all prefix sums and their values mod 7.
Given two prefixes that have the same mod 7 value, then the difference 
between their values must be divisible by 7. Thus, we find the biggest
distance between the same % 7 values across the entire array.
*/
