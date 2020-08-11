// December 2016—Cities and States: http://www.usaco.org/index.php?page=viewproblem2&cpid=667

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

map<string, int> cnt;
 
int main(void){
    //setIO("citystate");
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        string a, b, combo; cin >> a >> b;
        combo.pb(a[0]);
        combo.pb(a[1]);
        combo += b;
        cnt[combo]++;
    }
    
    int ans = 0;
    trav(e, cnt){
        string flipped, original = e.first;
        flipped.pb(original[2]);
        flipped.pb(original[3]);
        flipped.pb(original[0]);
        flipped.pb(original[1]);
        if(flipped != original && cnt.find(flipped) != cnt.end())
            ans += cnt[flipped] * cnt[original];
    }
    
    cout << ans/2 << endl;
    return 0;
}

/*
For every city-state pair, we can create a string from the first two characters
of the city and the state abbreviation, and store the number of times it occurs
in a map. Then, for each of these elements in the map, we can flip the first two
and last two characters and if we find this new string, then we can multiply the
number of both occurrences. We divide our total by 2 to get the answer as we 
double counted. 
*/

