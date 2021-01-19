// 2017 U.S. Open—Where's Bessie: http://usaco.org/index.php?page=viewproblem2&cpid=740
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define trav(a, x) for (auto& a: x)
#define ins insert
#define pq priority_queue
#define sz(x) (int)x.size()
#define rsz resize
#define endl "\n"

typedef long long ll;
typedef pair<int, int> pii; 

void setIO(string name){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

int N, ans = 0;
string img[20];

struct PCL{
    int i1, j1, i2, j2;
};

vector<PCL> V;
bool visited[20][20];

void ff(int i, int j, int c, int i1, int j1, int i2, int j2){
    visited[i][j] = true;
    if (i > i1 && img[i - 1][j] - 'A' == c && !visited[i - 1][j])
        ff(i - 1, j, c, i1, j1, i2, j2);
    if (i < i2 && img[i + 1][j] - 'A' == c && !visited[i + 1][j])
        ff(i + 1, j, c, i1, j1, i2, j2);
    if (j > j1 && img[i][j - 1] - 'A' == c && !visited[i][j - 1])
        ff(i, j - 1, c, i1, j1, i2, j2);
    if (j < j2 && img[i][j + 1] - 'A' == c && !visited[i][j + 1])
        ff(i, j + 1, c, i1, j1, i2, j2);
}

bool isPCL(int i1, int j1, int i2, int j2){
    int numColors = 0;
    int colorCount[26] = {0};
    for (int i = i1; i <= i2; i++)
        for (int j = j1; j <= j2; j++)
            visited[i][j] = false;
            
    for (int i = i1; i <= i2; i++){
        for (int j = j1; j <= j2; j++){
            if (!visited[i][j]){
                int c = img[i][j] - 'A';
                if (colorCount[c] == 0) numColors++;
                colorCount[c]++;
                ff(i, j, c, i1, j1, i2, j2);
            }
        }
    }
    
    if (numColors != 2) return false;
    bool one = false, multiple = false;
    for (int i = 0; i < 26; i++){
        if (colorCount[i] == 1) one = true;
        if (colorCount[i] > 1) multiple = true;
    }
    
    return (one && multiple);
}

bool nestledPCL(int x, int y){
    return V[x].i1 >= V[y].i1 && V[x].i2 <= V[y].i2 && V[x].j1 >= V[y].j1 && V[x].j2 <= V[y].j2;
}

bool maxPCL(int x){
    for (int i = 0; i < sz(V); i++)
        if (i != x && nestledPCL(x, i)) return false;
        
    return true;
}

int main(){
    //setIO("where");
    cin >> N;
    for (int i = 0; i < N; i++) cin >> img[i];
    for (int i1 = 0; i1 < N; i1++)
        for (int j1 = 0; j1 < N; j1++)
            for (int i2 = i1; i2 < N; i2++)
                for (int j2 = j1; j2 < N; j2++)
                    if (isPCL(i1, j1, i2, j2)){
                        PCL p = {i1, j1, i2, j2};
                        V.pb(p);
                    }
                    
    for (int i = 0; i < sz(V); i++)
        if (maxPCL(i)) ans++;
        
    cout << ans << endl;
    return 0;
}

/*
Since N is at max 20, there's quite a brute forcey solution using floodfill. 
http://usaco.org/current/data/sol_where_silver_open17.html
*/

