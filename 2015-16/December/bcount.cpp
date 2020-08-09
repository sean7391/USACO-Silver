//December 2015—Breed Counting: http://www.usaco.org/index.php?page=viewproblem2&cpid=572

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

int N, Q;
int cows[MAXN], h[MAXN], g[MAXN], j[MAXN];

int main() {
    //setIO("bcount"); 
    cin >> N >> Q;
    cows[0] = 0;
    for (int i = 1; i <= N; i++)
        cin >> cows[i];
        
    for (int i = 1; i <= N; i++){
        if (cows[i] == 1){
            h[i] = h[i - 1] + 1;
            g[i] = g[i - 1];
            j[i] = j[i - 1];
        } else if (cows[i] == 2){
            h[i] = h[i - 1];
            g[i] = g[i - 1] + 1;
            j[i] = j[i - 1];
        } else{
            h[i] = h[i - 1];
            g[i] = g[i - 1];
            j[i] = j[i - 1] + 1;
        }
    }

    while(Q--){
        int a, b; cin >> a >> b;
        cout << h[b] - h[a - 1] << " ";
        cout << g[b] - g[a - 1] << " ";
        cout << j[b] - j[a - 1] << endl;
    }
}

/*
Here, we can just use prefix sums on all the cows, which makes calculating
the number between an interval very easy and time efficient.
*/
