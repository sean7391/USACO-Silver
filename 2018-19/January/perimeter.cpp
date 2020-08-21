// January 2019: Icy Perimeter: http://www.usaco.org/index.php?page=viewproblem2&cpid=895

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
#define all(v) v.begin(), v.end()
#define MAXN 1005

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

int N, curSize = 0, curPer = -;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

void floodfill(int r, int c, int color){
    if(r < 0 || r >= N || c < 0 || c >= N || grid[r][c] != color){
        curPer++;
        return; 
    }
    if(visited[r][c]) return; 
    visited[r][c] = true; 
    curSize++; 
    
    for (int i = 0; i < 4; i++)
        floodfill(r + dx[i], c + dy[i], color);
}

int main() {
    //setIO("perimeter"); 
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            char c; cin >> c;
            if (c == '#') grid[i][j] = 1;
        }
    }
    
    int areaAns = 0, perAns = INT_MAX;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!visited[i][j] && grid[i][j] == 1){
                curSize = 0;
                curPer = 0;
                floodfill(i, j, 1);
                
                if (curSize > areaAns){
                    areaAns = curSize;
                    perAns = curPer;
                }
                
                if (curSize == areaAns){
                    if (curPer < perAns){
                        areaAns = curSize;
                        perAns = curPer;
                    }
                }
            }
     
    cout << areaAns << " " << perAns << endl;
    return 0;
}

/*
Quite the fun floodfill problem. You just have to
increment a perimeter counter whenever you reach the edge
of the grid or go outside the blob; this will ensure you 
always get the right perimeter. 
*/
