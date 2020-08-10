//February 2016—Circular Barn: http://www.usaco.org/index.php?page=viewproblem2&cpid=618

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

int N, ans = INT_MAX, arr[1005];

int solve(){
    int total = 0;
    queue<int> q;
    if (arr[0] == 0) return INT_MAX;
        
    if (arr[0] > 1)
        for (int i = 0; i < arr[0] - 1; i++)
            q.push(0);
        
    for (int i = 1; i < N; i++){
        if (q.empty() && arr[i] == 0) return INT_MAX;
            
        if (q.empty() && arr[i] == 1) continue;
            
        if (q.empty() && arr[i] > 1){
            for (int j = 0; j < arr[i] - 1; j++)
                q.push(i);
                
            continue;
        }
            
        if (!q.empty()){
            total += (i - q.front()) * (i - q.front());
            q.pop();
        }
        
        if (arr[i] > 0)
            for (int j = 0; j < arr[i]; j++)
                q.push(i);
    }
    
    return total;
}

int main(){
    //setIO("cbarn"); 
    cin >> N; 
    for (int i = 0; i < N; i++) cin >> arr[i];

    ans = min(ans, solve());
    for (int i = 1; i < N; i++){
        rotate(arr, arr + 1, arr + N);
        ans = min(ans, solve());
    }   
    
    cout << ans << endl;
}

/*
The main observation here is that we can pick up cows along the way and drop them;
we always want to drop the cows that have been picked up the longest, because of the 
squared mechanism. Silver constraints let us just try every single location on the circle,
and we can use a queue to simulate picking up and dropping off cows.
*/

