// December 2015—Switching on the Lights: http://www.usaco.org/index.php?page=viewproblem2&cpid=570

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

int N, M;
vector<pii> v[MAXN][MAXN];
bool visited[MAXN][MAXN];
bool lit[MAXN][MAXN];

bool isVisited(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N && visited[x][y];
}

bool isLit(int x,int y){
    return x >= 0 && x < N && y >= 0 && y < N && lit[x][y];
}

bool hasVisitedNeighbor(int x, int y){
    for(int k = 0; k < 4; k++){
        if(isLit(x + dx[k], y + dy[k]) && isVisited(x + dx[k], y + dy[k]))
            return true;
    }
    
    return false;
}

void ff(int r, int c){
    if(r < 0 || r >= N || c < 0 || c >= N || !lit[r][c] || visited[r][c]) return; 
    visited[r][c] = true; 
    
    for (int i = 0; i < v[r][c].size(); i++){
        int x = v[r][c][i].f, y = v[r][c][i].s;
        if (!lit[x][y]){
            lit[x][y] = true;
            if (hasVisitedNeighbor(x, y))
                ff(x, y);
        }
    }

    for (int i = 0; i < 4; i++)
        ff(r + dx[i], c + dy[i]);
}

int main() {
    // setIO("lightson"); 
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        x--; y--; a--; b--;
        v[x][y].pb(mp(a, b));
    }
    
    lit[0][0] = true;
    ff(0, 0);
    
    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (lit[i][j])
                ans++;
    
    cout << ans << endl;
    return 0;
}

/*
We can use floodfill to solve this problem. The catch is, if we light up a new room and 
it has a neighbor that has been visited already, then we have to floodfill the new room.

This is because, if we know it has a visited neighbor, then we can safely go to the new room,
and see what new rooms it can turn on.

At the end, we simply iterate across our lit graph and count the number of lit up rooms.
*/
