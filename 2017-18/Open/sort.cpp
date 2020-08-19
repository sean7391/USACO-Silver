// 2018 U.S. Open—Out of Sorts: http://www.usaco.org/index.php?page=viewproblem2&cpid=834

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

vector<pii> v;
int N, localMin = 1e9;

int main() {
    //setIO("sort"); 
    cin >> N; int arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = N - 1; i >= 0; i--){
        if (arr[i] < localMin){
            localMin = arr[i];
            v.pb(mp(localMin, 0));
        }
        else if (arr[i] > localMin){
            for (int j = 0; j < sz(v); j++)
                if (v[j].f < arr[i])
                    v[j].s++;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < sz(v); i++)
        ans = max(ans, v[i].s);
        
    cout << ans + 1 << endl;
    return 0;
}

/*
After some thought and sketching, one should be able to realize
that the answer is always going to be the maximum number of positions
a number has to move during the entire sort, +1 because we have to take
into account the original permutation. 

We can do this by iterating from the right, storing a vector of integer
pairs whenever we come across a local minimum, and as we iterate through,
increment the number of new numbers that are larger than the local mins
stored in the vector. Then we find the max at the end.

Note that we can ignore numbers of the same value. 
*/
