// 2017 U.S. Open—Paired Up: http://www.usaco.org/index.php?page=viewproblem2&cpid=738

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

int N; vector<pii> v;

int main() {
    setIO("pairup"); 
    cin >> N;
    for (int i = 0; i < N; i++){
        int x, y; cin >> x >> y;
        v.pb(mp(y, x));
    } 
    sort(v.begin(), v.end());
    
    int ans = 0, i = 0, j = N - 1;
    while (i <= j){
        int x = min(v[i].s, v[j].s);
        if (i == j) x /= 2;
        ans = max(ans, v[i].f + v[j].f);
        v[i].s -= x; v[j].s -= x;
        if (v[i].s == 0) i++;
        if (v[j].s == 0) j--;
    }
    
    cout << ans << endl;
    return 0;
}

/*
The optimal solution is sorting based on output, and then
pairing up cows from either end of the list. We can optimize this
by pairing up multiple cows at a time if there are multiple 
cows with the same output when we are pairing two outputs together.
*/

