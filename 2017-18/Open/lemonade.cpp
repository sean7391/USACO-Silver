// 2018 U.S. Open—Lemonade Line: http://www.usaco.org/index.php?page=viewproblem2&cpid=835

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
 
int N;
vi v;
 
int main() {
    //setIO("lemonade"); 
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
 
    int ans = N;
    for (int i = 0; i < N; i++){
    	if (v[i] < i){
    		ans = i;
    		break;
    	}
    }
 
    cout << ans << endl;
    return 0;
}

/*
Perhaps the easiest Silver problem of all time? Simply sort
the number of cows each cow is willing to wait behind in descending
order, and iterate from left to right; when we come across a cow 
whose wait amount is less than its index, then that index is the
answer.
*/
