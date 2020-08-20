// December 2018—Mooyo Mooyo: http://www.usaco.org/index.php?page=viewproblem2&cpid=860

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
#define MAXN 100

typedef long long ll;
typedef pair<int, int> pii; 

const int dx[4]= {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void setIO(string name){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int N, K, curSize = 0;
int grid[MAXN][10];
bool visited[MAXN][10];

void clear(){
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < 10; j++)
            visited[i][j] = false;
}

void ff(int r, int c, int color){
    if(r < 0 || r >= N || c < 0 || c >= 10 || grid[r][c] != color) return; 
    if(visited[r][c]) return; 
    visited[r][c] = true; 
    curSize++;
    
    for (int i = 0; i < 4; i++)
        ff(r + dx[i], c + dy[i], color);
}

void ffZero(int r, int c, int color){
    if(r < 0 || r >= N || c < 0 || c >= 10 || grid[r][c] != color) return; 
    if(visited[r][c]) return; 
    visited[r][c] = true; 
    grid[r][c] = 0;
    
    for (int i = 0; i < 4; i++)
        ffZero(r + dx[i], c + dy[i], color);
}

void gravity(){
    for (int j = 0; j < 10; j++){
        int cur = N - 1;
        for (int i = N - 1; i >= 0; i--){
            if (grid[i][j] > 0){
                int temp = grid[i][j];
                grid[i][j] = 0;
                grid[cur][j] = temp;
                cur--;
            }
        }
    }
}

int main() {
    setIO("mooyomooyo"); 
    cin >> N >> K;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < 10; j++){
            char c; cin >> c;
            grid[i][j] = c - '0';
        }
    }
    
    while (true){
        int cmpCnt = 0;
        clear();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < 10; j++)
                if (!visited[i][j] && grid[i][j] > 0){
                    curSize = 0;
                    ff(i, j, grid[i][j]);
                    
                    if (curSize >= K){
                        clear();
                        ffZero(i, j, grid[i][j]);
                        cmpCnt++;
                    }
                }

        if (cmpCnt == 0) break;
        gravity();
    }
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < 10; j++)
            cout << grid[i][j];
            
        cout << endl;
    }
    
    return 0;
}

/*
Probably my favorite Silver problem. We can use two floodfill functions; 
one to determine if the size of the component is >= K, and another to actually
switch all of those locations to zero. We simulate the process of gravity 
whenever we have floodfilled all the valid components, and do this until
no more such components exist. 
*/


