// February 2017—Why Did the Cow Cross the Road: http://www.usaco.org/index.php?page=viewproblem2&cpid=714

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

multiset<int> chickens;
vector<pii> cows;
int C, N;

int main(){
    //setIO("helpcross");
    cin >> C >> N;
    int x, y, cnt = 0;
    for (int i = 0; i < C; i++){
        cin >> x; 
        chickens.insert(x); 
    }
        
    for (int i = 0; i < N; i++){ 
        cin >> x >> y; 
        cows.pb(mp(y, x)); 
    } sort(cows.begin(), cows.end());
    
    for (int j = 0; j < N; j++) {
        auto chicken = chickens.lb(cows[j].s);
        if (chicken != chickens.end() && *chicken <= cows[j].f){
            cnt++;
            chickens.erase(chicken);
        }
    } 
     
    cout << cnt << endl;
    return 0;
}

/*
We can use greedy here; store the chickens in a multiset,
and then try assigning the earliest ending cow to a chicken,
as we will always have more options for the later ending cows,
so this is optimal. 
*/
