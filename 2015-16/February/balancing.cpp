// February 2016—Load Balancing: http://www.usaco.org/index.php?page=viewproblem2&cpid=619

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define f first
#define s second
#define sz(x) (int)x.size()
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define trav(a, x) for (auto& a: x)
#define ins insert
#define pq priority_queue
#define endl "\n"
#define all(v) v.begin(), v.end()

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

int N, a, b, ans = 1e9;
pii cows[1000];

int main() {
    //setIO("balancing"); 
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a >> b;
        cows[i] = mp(a, b);
    }
    sort(cows, cows + N);
    
    for (int i = 0; i < N; i++){
        int yLine = cows[i].s + 1;
        vector<pii> below, above;
        for (int j = 0; j < N; j++){
            if (cows[j].s < yLine)
                below.pb(cows[j]);
            else
                above.pb(cows[j]);
        }
        
        int b = 0, a = 0;
        while(b < sz(below) || a < sz(above)){
            int xBorder = 1e9;
            if (b < sz(below))
                xBorder = min(xBorder, below[b].f);
            if (a < sz(above))
                xBorder = min(xBorder, above[a].f);
            while(b < sz(below) && below[b].f == xBorder)
                b++;
            while(a < sz(above) && above[a].f == xBorder)
                a++;
                
            ans = min(ans, max(max(b, sz(below) - b), max(a, sz(above) - a)));
        }
    }
    
    cout << ans << endl;
    return 0;
}

/*
Here, we just try all horizontal lines and sweep our vertical lines across, and
calculate the min value of all four quadrants each time, effectively iterating
through all solutions.
*/

