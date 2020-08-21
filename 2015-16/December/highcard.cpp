//December 2015—High Card Wins: http://www.usaco.org/index.php?page=viewproblem2&cpid=571

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

vector<int> a, b;
bool owns[100001];

int main(){
    //setIO("highcard");
    int n, cnt = 0; cin >> n;
    for (int i = 0; i < n; i++){
        int temp; cin >> temp;
        owns[temp] = true;
    }
    
    for (int i = 1; i <= 2 * n; i++){
        if (owns[i]) b.pb(i);
        else a.pb(i);
    }
    
    int bi = 0, ei = 0;
    while (bi < n && ei < n){
        if (a[bi] > b[ei]){
            cnt++;
            bi++;
            ei++;
        }
        else
            bi++;
    }
    
    cout << cnt << endl;
    return 0;
}

/* 
This is a greedy problem. We always want to minimize the value of the card
that Bessie uses to beat Elsie's smallest unbeaten card—if one of Bessie's cards
is smaller than Elsie's smallest unbeaten card, then obviously we can't use it
and we can discard it.

We just have to make sure that the arrays containing both Bessie's and Elsie's 
cards are in sorted order, and we can do that with a boolean array and iterating 
through the array after reading in which ones belong to Elsie. 
*/

