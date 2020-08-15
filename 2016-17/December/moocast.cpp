// December 2016—Moocast: http://www.usaco.org/index.php?page=viewproblem2&cpid=668

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

bool canTransmit[201][201];

int dfs(int cur, bool canHear[]){
    if (canHear[cur]) return 0;
    canHear[cur] = true;
    int cnt = 1;
    for (int i = 0; i < sizeof(canTransmit[cur]); i++)
        if(canTransmit[cur][i])
            cnt += dfs(i, canHear);
            
    return cnt;
}

int main() {
    //setIO("moocast");
    int N; cin >> N;
    int x[N], y[N], p[N];
    for (int i = 0; i < N; i++)
        cin >> x[i] >> y[i] >> p[i];
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if (dist <= p[i] * p[i])
                canTransmit[i][j] = true;
        }
    }
    
    int cnt = 1;
    for (int i = 0; i < N; i++){
        bool canHear[N]; 
        memset(canHear, false, sizeof(canHear));
        cnt = max(cnt, dfs(i, canHear));
    }
    
    cout << cnt << endl;
}

/*
We can initialize a two dimensional boolean array canTransmit where if 
canTransmit[i][j] is true, then cow i has enough power to transmit a message 
to cow j. Now, we just iterate through every cow and dfs to find the number
of cows it can reach, and take the maximum of all these values. 
*/

