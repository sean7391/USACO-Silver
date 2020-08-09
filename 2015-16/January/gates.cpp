//January 2016—Build Gates: http://www.usaco.org/index.php?page=viewproblem2&cpid=596

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

int N; string S;
int grid[2001][2001];
bool visited[2001][2001];

void ff(int i, int j){
    if (i < 1 || j < 1 || i > 2000 || j > 2000) return;
    if (visited[i][j]) return;
    if (grid[i][j] == 1) return;
    
    visited[i][j] = true;
    for (int k = 0; k < 4; k++)
        ff(i + dx[k], j + dy[k]);
}

int main() {
    //setIO("gates"); 
    cin >> N >> S;
    int x = 1000, y = 1000;
    for (int i = 0; i < N; i++){
        char c = S[i];
        int deltaX = 0, deltaY = 0;
        if (c == 'N') deltaY = 1;
        else if (c == 'S') deltaY = -1;
        else if (c == 'E') deltaX = 1;
        else deltaX = -1;
        
        for (int i = 0; i < 2; i++){
            x += deltaX; y += deltaY;
            grid[x][y] = 1;
        }
    }
    
    int cmp = 0;
    for (int i = 1; i <= 2000; i++){
        for (int j = 1; j <= 2000; j++){
            if (!visited[i][j] && grid[i][j] == 0){
                ff(i, j);
                cmp++;
            }
        }
    }
    
    cout << cmp - 1 << endl;
    return 0;
}

/*
All we need to do is find the number of components in the graph after
installing the fences; the number of gates will be one less than the number 
of components, because a gate connects two components. 

The hardest part is probably just reconstructing the fences themselves;
we can actually just start from the middle of an array, and represent each
section of a fence with two array spots.
*/
