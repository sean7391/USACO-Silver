//January 2016—Angry Cows: http://www.usaco.org/index.php?page=viewproblem2&cpid=594

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

int N, K;
vector<int> v;

bool check(int R){
    int target = v[0] + R, num = 1;
    for (int i = 0; i < N; i++){
        if (v[i] > target + R){
            target = v[i] + R;
            num++;
        }
        
        if (num > K)
            return false;
    }
    
    return true;
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
    setIO("angry"); 
    cin >> N >> K;
    for (int i = 0; i < N; i++){
        int temp; cin >> temp; 
        v.pb(temp);
    } 
    sort(v.begin(), v.end());
    
    cout << search() << endl;
    return 0;
}

/*
We can binary search on answer, as we are trying to find the minimum possible answer.
Our greedy check function tests the number of cows needed to detonate all the haybales with 
power R; if this is larger than K, then it returns false.
*/

