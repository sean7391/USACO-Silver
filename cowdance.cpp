// January 2017—Cow Dance Show: http://www.usaco.org/index.php?page=viewproblem2&cpid=690

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

int N, maxT;
vector<int> v;

int check(int K){
    int lastTime = 0;
    pq<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++){
        if (pq.size() == K){
            lastTime = pq.top();
            pq.pop();
        }
        if (lastTime + v[i] > maxT) return false;
        pq.push(lastTime + v[i]);
    }
    
    return true;
}

int search(){
    int left = 0, right = N + 1, ans = -1;
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
    //setIO("cowdance"); 
    cin >> N >> maxT;
    for (int i = 0; i < N; i++){
        int temp; cin >> temp;
        v.pb(temp);
    } 
    
    cout << search() << endl;
}

/*
We can binary search on the answer, and use a priority queue
in our check function to determine which cow must leave the 
stage whenever the stage fills up. 
*/
