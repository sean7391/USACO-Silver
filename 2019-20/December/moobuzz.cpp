// December 2019—Moobuzz: http://www.usaco.org/index.php?page=viewproblem2&cpid=966

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
 
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}

int N; 
vector<int> v;
 
bool ok(int x){
    return x % 3 && x % 5; 
}

int solve(int N){ 
	int x = (N - 1) / 8;
	return v[N - 8 * x - 1] + 15 * x;
}
 
int main(){
  //setIO("moobuzz");
	for (int i = 1; i < 16; i++) if (ok(i)) v.pb(i);
	        
	int N; cin >> N;
	cout << solve(N) << endl;
  return 0;
}

/*
For any 15 consecutive turns, eight numbers are spoken; we can
calculate the first eight numbers beforehand, and then use recursion.
Just find which set of 15 consecutive numbers the desired number is in,
find the corresponding number for when N <= 8, and add 15 * set.
*/


