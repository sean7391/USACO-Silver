// December 2018—Convention: http://www.usaco.org/index.php?page=viewproblem2&cpid=858

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
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define endl "\n"

typedef long long ll;
typedef pair<int, int> pii; 

const int dx[4]= {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void setIO(string name){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int N, M, C;
vector<int> v;

bool check(int wait){
    int wagons = 1, firstArrival = v[0], firstIndex = 0;
    for (int i = 1; i < N; i++){
        if (v[i] - firstArrival > wait || i + 1 - firstIndex > C){
            wagons++;
            firstArrival = v[i];
            firstIndex = i;
        }
    }
    
    if (wagons <= M) return true;
    else return false;
}

int search(){
    int left = 0, right = MAXN, ans = -1;
    while (left <= right){
        int mid = (left + right)/2;
        if (!check(mid)){
            left = mid + 1;
            ans = mid;
        }
        else
            right = mid - 1;
    }
    
    return ans + 1;
}

int main() {
    //setIO("convention"); 
    cin >> N >> M >> C;
    for (int i = 0; i < N; i++){
        int t; cin >> t;
        v.pb(t);
    } 
    sort(v.begin(), v.end());
    
    cout << search() << endl;
    return 0;
}

/*
This is binary search with a greedy check function. Our check function
finds the minimum number wagons for a certain wait time, and if this value
is less than or equal to the real number of wagons then the function returns
true. 
*/
