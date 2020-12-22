#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define endl "\n"

typedef long long ll;
typedef pair<ll, ll> pii; 

ll N, ans;
vector<pii> cows;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N; 
    cows.resize(N);
    ans = N + 1;
    for (ll i = 0; i < N; i++){
        ll a, b; cin >> a >> b;
        cows[i].f = a; cows[i].s = b;
    }
    sort(cows.begin(), cows.end());

    for (ll i = 0; i < N - 1; i++){
        for (ll j = i + 1; j < N; j++){
            int bot = 0, top = 0;
            for (ll k = i + 1; k < j; k++){
                if (cows[k].s < min(cows[i].s, cows[j].s)) bot++;
                if (cows[k].s > max(cows[i].s, cows[j].s)) top++;
            }
            ans += (bot + 1) * (top + 1);
        }
    }
    
    cout << ans << endl;
    return 0;
}

