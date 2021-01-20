// December 2017—Milk Measurement: http://www.usaco.org/index.php?page=viewproblem2&cpid=763

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

struct measurement{
    int day, cow, delta;
};

int N, G, ans = 0;
vector<measurement> A;
map<int, int, greater<int>> cnts;
map<int, int> mp;

int main(){
    //setIO("measurement");
    cin >> N >> G; A.rsz(N);
    trav(m, A) cin >> m.day >> m.cow >> m.delta;
    sort(A.begin(), A.end(), [](const measurement &a, const measurement &b){
        return a.day < b.day;
    });
    
    cnts[0] = N + 1;
    trav(m, A){
        bool wastop = (mp[m.cow] == cnts.begin()->f);
        int oldCnt = cnts[mp[m.cow]];
        cnts[mp[m.cow]]--;
        if (oldCnt == 1) cnts.erase(mp[m.cow]);
        
        mp[m.cow] += m.delta;
        cnts[mp[m.cow]]++;
        int curCnt = cnts[mp[m.cow]];
        
        bool isTop = (mp[m.cow] == cnts.begin()->f);
        if (wastop){
            if (!isTop || oldCnt != 1 || curCnt != 1)
                ans++;
        }
        else if (isTop) ans++;
    }
    
    cout << ans << endl;
    return 0;
}

/*
We can use maps to keep track of the frequency of cow measurement, and the 
measurement for each cow. If a cow in question wasn't at the top but is at the 
top now, then the display obviously has to be changed. 

If the cow was already at the top, and is no longer at the top, then the display
has to be changed. 

If the cow was already at the top, and there was at least one other cow at the top
with it, then the display has to be changed.

If the cow was already at the top, and there are currently more than one cow at the top,
then the display has to be changed. 
*/

