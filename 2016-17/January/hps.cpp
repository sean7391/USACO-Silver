// January 2017—Hoof Paper Scissors: http://www.usaco.org/index.php?page=viewproblem2&cpid=691

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
#define MAXN 100005

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

int N, P[MAXN], H[MAXN], S[MAXN];

int findMax(int a, int b, int c){
    int maxTwo = max(a, b);
    return max(maxTwo, c);
}

int main() {
    //setIO("hps"); 
    cin >> N;
    for (int i = 1; i <= N; i++){
        char c; cin >> c;
        if (c == 'H'){
            H[i] = H[i - 1] + 1;
            P[i] = P[i - 1];
            S[i] = S[i - 1];
        } else if (c == 'P'){
            H[i] = H[i - 1];
            P[i] = P[i - 1] + 1;
            S[i] = S[i - 1];
        } else{
            H[i] = H[i - 1];
            P[i] = P[i - 1];
            S[i] = S[i - 1] + 1;
        }
    }
    
    int maxN = findMax(H[N], P[N], S[N]);
    for (int i = 1; i <= N - 1; i++){
        int maxH = max(P[N] - P[i], S[N] - S[i]);
        maxN = max(maxN, H[i] + maxH);        
        
        int maxP = max(H[N] - H[i], S[N] - S[i]);
        maxN = max(maxN, P[i] + maxP);
        
        int maxS = max(H[N] - H[i], P[N] - P[i]);
        maxN = max(maxN, S[i] + maxS);
    }
    
    cout << maxN << endl;
}

/*
We create prefix sums for all three moves, and find the highest number
of games we can win without switching; then, we iterate through every index,
and at each, we find the highest number of games we can win if we switch
to each different gesture at that index.
*/


