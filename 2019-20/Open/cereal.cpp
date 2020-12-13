// 2020 U.S. Open—Cereal: http://www.usaco.org/index.php?page=viewproblem2&cpid=1039

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

const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int N, M;
int f[100001], s[100001], occ[100001], ans[100001];

int main() {
    //setIO("cereal"); 
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> f[i] >> s[i];
    
    int cnt = 0;
    for (int i = N - 1; i >= 0; i--){
        int j = i, pos = f[i];
        while (true){
            if (occ[pos] == 0){
                occ[pos] = j;
                cnt++;
                break;
            }
            else if (occ[pos] < j) break; 
            else{
                int k = occ[pos];
                occ[pos] = j;
                if (pos == s[k]) break; 
                j = k; 
                pos = s[k]; 
            }
        }
        
        ans[i] = cnt;
    }
    
    for (int i = 0; i < N; i++) cout << ans[i] << endl;
    return 0;
}

/*
We can start from the end and add cows to the front of the line. 
Obviously, the new cow's first choice will be given to him. 
If this first choice was not picked by anyone else after him, then nothing changes (cereal count is incrememented).
If a cow had taken the front cow's first choice, and it was their second choice, then that cow gets nothing now (no increment).
If a cow had taken the front cow's first choice, and it was their first choice, and their second choice was taken by
a cow earlier than them in line, then they too will not get anything. 
However, if a cow had taken the front cow's first choice, and it was their first choice, and their second choice was taken
by someone later than them in line, then they get the second choice but this could cause a cascade that calls for recursion. 
It is possible that their second choice was not taken by anyone too. Either way, recursion is necessary. 

*/

