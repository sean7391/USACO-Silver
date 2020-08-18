// January 2018—Rental Service: http://www.usaco.org/index.php?page=viewproblem2&cpid=787

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
 
int N, M, R;
pii buy[100000];
ll bought[100000], cow[100000], rent[100000]; 
 
bool cmp(const pii& a, const pii& b){
    return a.s < b.s;
}
 
int main(){
    setIO("rental");
    cin >> N >> M >> R;
    for(int i = 0; i < N; i++) cin >> cow[i];
    for(int i = 0; i < M; i++) cin >> buy[i].f >> buy[i].s;
    for(int i = 0; i < R; i++) cin >> rent[i]; 
    sort(cow, cow + N);
    sort(buy, buy + M, cmp);
    sort(rent, rent + R, greater<int>());
    
    int j = M - 1;
    for(int i = N - 1; i >= 0; i--){
        int cur = cow[i];
        ll cnt = 0;
        while (cur > 0 && j >= 0){
            if (buy[j].f > cur){
                cnt += cur * buy[j].s;
                buy[j].f -= cur;
                cur = 0;
            }
            else{
                cnt += buy[j].f * buy[j].s;
                cur -= buy[j].f;
                buy[j].f = 0;
                j--;
            }
        }
 
        bought[i] = cnt;
    }
 
    ll ans = 0;
    for(int i = 0; i < N; i++) ans += max(bought[i], rent[i]);
 
    cout << ans << endl;
    return 0;
}

/*
We basically want to rent the cows with the lowest milk production at the highest
profit, and sell the milk of the cows with the most milk production. For each cow, 
we can calculate how much would be made if it were to be rented, as well as how
much profit it would make from selling the milk; if we sort the cows in ascending
order of milk production, then our rental prices should be sorted in descending order
and milk profit in ascending. Then, we can compare both profits at each cow and add
this to our total.

Here's a good explanation:
https://www.youtube.com/watch?v=9lgKEzEOTrM
*/
