// January 2018—Lifeguards: http://www.usaco.org/index.php?page=viewproblem2&cpid=786

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
 
int N, smallest = INT_MAX, largest = -1;
vector<pii> v;
vector<pii> v2;
 
int main() {
    setIO("lifeguards"); 
    cin >> N;
    for (int i = 0; i < N; i++){
        int a, b; cin >> a >> b;
	smallest = min(smallest, min(a, b));
	largest = max(largest, max(a, b));
	v.pb(mp(a, 1));
	v.pb(mp(b, 0));
	    v2.pb(mp(a, b));
    }
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());

    int curEnd = v2[0].s, minAlone = INT_MAX, cur = 1;
    for (int i = 1; i < N; i++){
	if (v2[i].s <= curEnd) minAlone = 0;
	else curEnd = v2[i].s;
    }

    int total = largest - smallest;
    for (int i = 1; i < 2 * N; i++){
	if (cur == 0 && v[i].s == 1)
	    total -= (v[i].f - v[i - 1].f);
	    else if (cur == 1)
		minAlone = min(minAlone, v[i].f - v[i - 1].f);

	    if (v[i].s == 1) cur++;
	    else cur--;
	}

    cout << total - minAlone << endl;
    return 0;
}

/*
Our goal is to calculate the minimum time a lifeguard is working alone, and subtract
this from the total time there is at least one lifeguard working. We can consider each 
time a lifeguard goes onto a shift or comes off a shift as an event, and then process 
all of these events in order. Whenever we get to an event and there is only one lifeguard 
currently working, then the time between the current event and the last event must be during 
when a lifeguard was working alone. Thus, we can calculate the minimum time any lifeguard
is working alone with this method; however, it does not cover the case where a lifeguard's 
shift may be entirely within that of another lifeguard—therefore, we have to separately 
determine if such a case exists, in which case the minimum time is zero.
*/
