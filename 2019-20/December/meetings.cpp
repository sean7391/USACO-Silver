// December 2019—Meetings: http://www.usaco.org/index.php?page=viewproblem2&cpid=967

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

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

//Ben Qi Solution
int N, L;
vector<int> w, x, d;

int calcTime(){
    vector<int> left, right;
    for (int i = 0; i < N; i++){
        if (d[i] == -1) left.pb(x[i]);
        else right.pb(x[i]);
    }
    
    vector<pii> v;
    for (int i = 0; i < sz(left); i++)
        v.pb({left[i], w[i]});
        
    for (int i = 0; i < sz(right); i++)
        v.pb({L - right[i], w[sz(left) + i]});
        
    sort(all(v));
    int total = 0; trav(t, v) total += t.s;
    trav(t, v){
        total -= 2 * t.s;
        if (total <= 0) return t.f;
    }
}

int main() {
    // setIO("meetings");
    cin >> N >> L;
    w.resize(N); x.resize(N); d.resize(N); vector<int> W, X, D;
    for (int i = 0; i < N; i++) cin >> w[i] >> x[i] >> d[i];
    vector<int> inds(N); iota(all(inds), 0);
    sort(all(inds), [](int a, int b){return x[a] < x[b];});
    trav(t, inds){
        W.pb(w[t]);
        X.pb(x[t]);
        D.pb(d[t]);
    } 
    swap(w, W); swap(x, X); swap(d, D); // sort by x coordinates
    
    int t = calcTime(), ans = 0;
    queue<int> q;
    for (int i = 0; i < N; i++){
        if (d[i] == -1){
            while (sz(q) && q.front() + 2 * t < x[i]) q.pop();
            ans += sz(q);
        }
        else q.push(x[i]);
    }
    
    cout << ans << endl;
    return 0;
}

/*
http://www.usaco.org/current/data/sol_meetings_silver_dec19.html
First, sort the cows by x-coordinate.

Then, find T. We do this by realizing that the the x number of cows
going left must be the x left-most cows due to meetings, and the same
for those going right. So we can sort by arrival at the barns, and calculate
the time. 

Finally, we can use a queue to determine the number of meetings, using the observation
that two cows will meet if they have opposite directions and 2 * time + the initial location
of the cow going in the positive direction is greater than or equal to the initial locatin of 
the cow going in the negative direction. The queue works because as we move along and enumerate
all which are going in the negative direction, a cow going in the positive direction that didn't 
work for a previous cow won't work with a cow further down.
*/
