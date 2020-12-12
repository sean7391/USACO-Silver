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
#define INF 2000000000

typedef long long ll;
typedef pair<ll, ll> pii; 

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int N, M;
vector<pii> safe;

bool check(ll x){
    ll prev = -1ll * INF * INF;
    
    int cnt = 0;
    trav(interval, safe){
        while (max(prev + x, interval.f) <= interval.s){
            prev = max(prev + x, interval.f);
            cnt++;
            if (cnt >= N) break;
        }
        
        if (cnt >= N) break;
    }
 
    return (cnt >= N);
}

ll search(){
    ll left = 0, right = 1e18, ans = 0;
    while (left <= right){
        ll mid = (left + right)/2;
        if (check(mid)){
            left = mid + 1;
            ans = mid;
        }
        else
            right = mid - 1;
    }
    
    return ans;
}


int main() {
    // setIO("socdist");
    cin >> N >> M;
    for (ll i = 0; i < M; i++){
        ll a, b; cin >> a >> b;
        safe.pb({a, b});
    }
    sort(beg(safe), en(safe));
    
    cout << search() << endl;
    return 0;
}

/*
Just binary search for the max distance. The check function uses greedy,
finding the leftmost possible place to put a cow given the distancing 
constraint. 
*/
