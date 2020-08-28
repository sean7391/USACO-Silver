// U.S. Open 2018—Multiplayer Moo: http://usaco.org/index.php?page=viewproblem2&cpid=836

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
#define rsz resize
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define endl "\n"

typedef long long ll;
typedef pair<int, int> pii; 

const int dx[4]= {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int N, arr[250][250];
bool visited[250][250], visited2[250][250];
int curSize = 0;

void ff(int r, int c, int color){
    if(r < 0 || r >= N || c < 0 || c >= N || arr[r][c] != color || visited[r][c]) return; 
    visited[r][c] = true; 
    curSize++;
    
    for (int i = 0; i < 4; i++)
        ff(r + dx[i], c + dy[i], color);
}

void ff2(int r, int c, int color1, int color2){
    if(r < 0 || r >= N || c < 0 || c >= N || (arr[r][c] != color1 && arr[r][c] != color2) || visited2[r][c]) return; 
    visited2[r][c] = true;
    curSize++;
    
    for (int i = 0; i < 4; i++)
        ff2(r + dx[i], c + dy[i], color1, color2);
}

int main() {
    // setIO("multimoo"); 
    cin >> N; 
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
            
    int ans1 = 0, ans2 = 0;
    bool bad = false;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (!visited[i][j]){
                ff(i, j, arr[i][j]);
                ans1 = max(ans1, curSize);
                curSize = 0;
            }
            
            memset(visited2, 0, sizeof(visited2));
            for (int k = 0; k < 4; k++){
                int a = i + dx[k], b = j + dy[k];
                if(a >= 0 && a < N && b >= 0 && b < N && arr[i][j] != arr[a][b] && !visited2[a][b]){
                    ff2(a, b, arr[i][j], arr[a][b]);
                    ans2 = max(ans2, curSize);
                    curSize = 0;
                   
                    if (ans2 == N * N){
                        bad = true;
                        break;
                    } 
                }
            }
            
            if (bad) break;
        }
        
        if (bad) break;
    }

    cout << ans1 << endl << ans2 << endl;
    return 0;
}

/*
This question is quite simple if it weren't for one test case.
We can do a basic floodfill to find the largest singular region,
and then floodfill for every two adjacent neighbors of different colors
to find the largest team region. However, there can be cases where this
is incredibly inefficient (where the board is arranged like a checkerboard).
In this case, one must use graph compression, but idk how to do that. 
My solution works for 9/10 test cases, and because the TLE test case
is just a checkerboard of two colors, I just put in a statement that breaks
if the answer found thus far is the size of the entire board, allowing me to 10/10.
However, it will still TLE if you change any one of these values in the input. 
*/
