// December 2016—Counting Haybales: http://www.usaco.org/index.php?page=viewproblem2&cpid=666

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

int N, Q;
vector<int> v;

int main() {
    // setIO("haybales"); 
    cin >> N >> Q;
    for (int i = 0; i < N; i++){
    	int a; cin >> a;
    	v.pb(a);
    }
    sort(v.begin(), v.end());
    
    while(Q--){
    	int a, b; cin >> a >> b;
    	cout << ub(v.begin(), v.end(), b) - lb(v.begin(), v.end(), a) << endl;
    }
    
    return 0;
}	

/*
This problem becomes extremely easy if you know how upper_bound and lower_bound work.
*/


