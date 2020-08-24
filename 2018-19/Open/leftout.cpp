// U.S. Open 2019—Left Out: http://www.usaco.org/index.php?page=viewproblem2&cpid=942

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

typedef long long ll;
typedef pair<int, int> pii; 

const int dx[4]= {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void setIO(string name){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

char grid[1000][1000];

int num(int i1, int j1, int i2, int j2, int b){
    int total = 0;
    for (int i = i1; i <= i2; i++)
        for (int j = j1; j <= j2; j++)
            if (grid[i][j] == b)
                total++;
                
    return total;
}

int main(){
    //setIO("leftout");
    int N; cin >> N; string s;
    for (int i = 0; i < N; i++){
        cin >> s;
        for (int j = 0; j < N; j++)
            if (s[j] == 'L')
                grid[i][j] = 1;
    }
    
    for (int i = 1; i < N; i++){
        grid[i][0] ^= grid[0][0];
        for (int j = 1; j < N; j++)
            grid[i][j] ^= grid[0][j] ^ grid[i][0];
    }
    
    if (num(1, 1, N - 1, N - 1, 0) == 0){
        cout << "1 1" << endl;
        return 0;
    }
    
    if (num(1, 1, N - 1, N - 1, 1) == N - 1){
        for (int j = 1; j < N; j++)
            if (num(1, j, N - 1, j, 1) == N - 1){
                cout << 1 << " " << j + 1 << endl;
                return 0;
            }
        for (int i = 1; i < N; i++)
            if (num(i, 1, i, N - 1, 1) == N - 1){
                cout << i + 1 << " " << 1 << endl;
                return 0;
            }
            
        cout << -1 << endl;
        return 0;
    }
    
    if (num(1, 1, N - 1, N - 1, 1) != 1){
        cout << -1 << endl;
        return 0;
    }
    
    for (int i = 1; i < N; i++)
        for (int j = 1; j < N; j++)
            if (grid[i][j] == 1)
                cout << i + 1 << " " << j + 1 << endl;
                
    return 0;
}

/*
Playing around with smaller cases can yield the observation that
if we flip the top row and leftmost column so that they are filled with
0s, then if the remaining numbers are all 1, then the exceptional cow
is in the top left corner; if there is one row or one column that is filled with
1s, then the first element is the exceptional cow; if there is exactly one 1
somewhere else, then that is the exceptional cow. 

Otherwise, no such cow exists. 
*/

