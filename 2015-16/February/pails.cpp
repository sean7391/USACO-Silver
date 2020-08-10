// February 2016—Milk Pails: http://www.usaco.org/index.php?page=viewproblem2&cpid=615

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

int X, Y, K, M;

int main() {
    //setIO("pails"); 
    cin >> X >> Y >> K >> M;
    bool can[X + 1][Y + 1];
    for (int i = 0; i < X + 1; i++)
        for (int j = 0; j < Y + 1; j++)
            can[i][j] = false;
    
    can[0][0] = true;
    while (K--){
        bool next[X + 1][Y + 1];
        for (int i = 0; i < X + 1; i++)
            for (int j = 0; j < Y + 1; j++)
                next[i][j] = false;
                
        for (int i = 0; i < X + 1; i++){
            for (int j = 0; j < Y + 1; j++){
                if (can[i][j]){
                    next[i][j] = true;
                    next[0][j] = true;
                    next[X][j] = true;
                    next[i][0] = true;
                    next[i][Y] = true;
                    int moveRight = min(i, Y - j);
                    next[i - moveRight][j + moveRight] = true;
                    int moveLeft = min(X - i, j);
                    next[i + moveLeft][j - moveLeft] = true;
                }
            }
        }
        
        for (int i = 0; i < X + 1; i++)
            for (int j = 0; j < Y + 1; j++)
                can[i][j] = next[i][j];

    }
    
    int ans = INT_MAX;
    for (int i = 0; i < X + 1; i++)
        for (int j = 0; j < Y + 1; j++)
            if (can[i][j])
                ans = min(ans, abs(i + j - M));
    
    cout << ans << endl;
    return 0;
}

/*
Given the two buckets, we have these states:
Pour X units of milk in the size X bucket and pour B units of milk in the size Y bucket.
Pour 0 units of milk in the size X bucket and pour B units of milk in the size Y bucket.
Pour A units of milk in the size X bucket and pour Y units of milk in the size Y bucket.
Pour A units of milk in the size X bucket and pour 0 units of milk in the size Y bucket.
Pour from X to Y
Pour from Y to X

We can basically do recursion on a two dimensional array and just keep doing all of these
operations for every given pair of buckets, and at the end iterate and find the minimum
difference.
*/
