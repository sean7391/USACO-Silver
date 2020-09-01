// January 2020—Loan Repayment: http://www.usaco.org/index.php?page=viewproblem2&cpid=991 

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

ll N, K, M;

bool check(ll X){
    ll G = 0, days = 0;
    while (days < K){
        ll Y = (N - G)/X;
        if (Y <= M){
            G += (K - days) * M;
            break;
        }
        
        ll rem = (N - G) % X;
        ll numDays = rem / Y;
        
        G += numDays * Y; days += numDays;
        G += Y; days++;
    }
    
    return G >= N;
}

ll search(){
    ll left = 1, right = 1e12, ans = -1;
    while (left <= right){
        ll mid = (left + right)/2;
        if (check(mid)){
            left = mid + 1;
            ans = mid;
        }
        else
            right = mid - 1;
    }
    
    return ans;
}

int main(){
    // setIO("loan"); 
    cin >> N >> K >> M;
    cout << search() << endl;
    return 0;
}

/*
Binary search on answer and be careful for int overflow.
Keep track of the number of gallons we give as we increase the 
number of days. Notice that if at any point Y is less than M, then
Y will always be M; thus we can fast forward to the end.

Otherwise, we can find the number of days we can continue giving Y
gallons of milk by taking the number of gallons remaining modulo X,
and then dividing this number by Y. Add this to our totals, and don't
forget that we still need to give Y once aside from the remaining amount.
*/

