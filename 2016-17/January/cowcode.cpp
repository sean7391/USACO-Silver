// January 2017—Secret Cow Code: http://www.usaco.org/index.php?page=viewproblem2&cpid=692

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

ll n; string S;

char solve(ll total, ll n){
    if (n < sz(S))
        return S[n];
    if (n >= total/2)
        return solve(total/2, (n - 1) % (total/2));
    else
        return solve(total/2, n);
}

int main() {
    //setIO("cowcode"); 
    cin >> S >> n;
    ll total = sz(S);
    
    while (total < n) 
        total *= 2;
    
    cout << solve(total, n - 1) << endl;
    return 0;
}

/*
An interesting recursion problem I still sometimes have issues
wrapping my head around. 
Cararra has a video on it: https://www.youtube.com/watch?v=ktjUV2667RU
*/

