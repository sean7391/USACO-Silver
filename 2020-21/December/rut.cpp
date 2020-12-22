#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define f first
#define s second
#define trav(a, x) for (auto& a: x)
#define sz(x) (int)x.size()
#define endl "\n"
#define MAXN 1005

typedef long long ll;
typedef pair<int, int> pii; 

struct cow{
    int x, y, i;
};

bool cmp(cow a, cow b){
    return a.y < b.y;
}

bool cmp2(cow a, cow b){
    return a.x < b.x;
}

int N; 
vector<int> cows[1001];
vector<cow> east, north;

int ans(int pos){
    int res = 0;
    trav(c, cows[pos]){
        if (sz(cows[c]) == 0) res++;
        else res += ans(c) + 1;
    }
    
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        char c; int a, b; cin >> c >> a >> b;
        cow t; t.x = a; t.y = b; t.i = i;
        if (c == 'E') east.pb(t);
        else north.pb(t);
    }
    sort(east.begin(), east.end(), cmp);
    sort(north.begin(), north.end(), cmp2);
    
    trav(e, east){
        for (int i = 0; i < sz(north); i++){
            if (north[i].y > e.y || north[i].x < e.x) continue;
            int t = north[i].x - e.x;
            int northY = north[i].y + t;
            if (northY == e.y) continue;
            if (northY > e.y){
                cows[north[i].i].pb(e.i);
                break;
            }
            else{
                cows[e.i].pb(north[i].i);
                north.erase(north.begin() + i);
                i--;
            }
        }
    }
    
    for (int i = 0; i < N; i++) cout << ans(i) << endl;
    return 0;
}

