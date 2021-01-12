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
typedef pair<int, int> Point;

bool ycmp(Point a, Point b){
    return a.s < b.s;
}

int N, pSum[2501][2501];
Point P[2501];
ll ans = 0;

int rsum(int x1, int y1, int x2, int y2){
    return pSum[x2 + 1][y2 + 1] - pSum[x2 + 1][y1] - pSum[x1][y2 + 1] + pSum[x1][y1];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++){
        int x, y; cin >> x >> y;
        P[i] = {x, y};
    }
    sort(P, P + N);
    for (int i = 0; i < N; i++) P[i].f = i + 1;
    sort(P, P + N, ycmp);
    for (int i = 0; i < N; i++) P[i].s = i + 1;
    
    for (int i = 0; i < N; i++) pSum[P[i].f][P[i].s] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            pSum[i][j] += pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1];
            
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++){
            int x1 = min(P[i].f, P[j].f) - 1;
            int x2 = max(P[i].f, P[j].f) - 1;
            ans += rsum(0, i, x1, j) * rsum(x2, i, N - 1, j);
        }
     
    cout << ans + 1 << endl;
    return 0;
}

