// February 2017—Why Did the Cow Cross the Road III: http://www.usaco.org/index.php?page=viewproblem2&cpid=716

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
#define endl "\n"
#define ALL(v) v.begin(), v.end()
#define MAXN 105

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

int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int cowx[MAXN], cowy[MAXN];
vector<pii> roads[MAXN][MAXN];
int N, K, R;

void ff(int i, int j, int cmp){
    if(i < 1 || j < 1 || i > N || j > N || visited[i][j]) return;
    visited[i][j] = true;
    grid[i][j] = cmp;
    for(int k = 0; k < 4; k++){
        int x = i + dx[k], y = j + dy[k];
        if(find(ALL(roads[i][j]), mp(x,y)) == roads[i][j].end())
            ff(x, y, cmp);
    }
}

int main() {
    setIO("countcross");
    cin >> N >> K >> R;
    for (int i = 0; i < R; i++){
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        roads[a][b].pb(mp(x, y));
        roads[x][y].pb(mp(a, b));
    }
    for (int i = 0; i < K; i++)
        cin >> cowx[i] >> cowy[i];
        
    int cmp = 0;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (!visited[i][j])
                ff(i, j, cmp);
            
            cmp++;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < K; i++){
        for (int j = i + 1; j < K; j++){
            if (grid[cowx[i]][cowy[i]] != grid[cowx[j]][cowy[j]])
                ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}

/*
We can use floodfill here, and use a 2D adjacency matrix to store
all the roads bounding each square on the grid. Then, whenever we floodfill
a component, we mark that component with a certain color, and then compare 
all the cows with one another, and if two cows have a different component
color, then we increment our answer.
*/
