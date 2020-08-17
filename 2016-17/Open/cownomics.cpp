// 2017 U.S. Open—Bovine Genomics: http://www.usaco.org/index.php?page=viewproblem2&cpid=739
 
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
 
int N, M, arr[64], spotty[500][50], plain[500][50];
 
bool isValid(int a, int b, int c){
	bool val = true;
	for (int i = 0; i < N; i++)
		arr[spotty[i][a] * 16 + spotty[i][b] * 4 + spotty[i][c]] = 1;
 
	for (int i = 0; i < N; i++)
		if (arr[plain[i][a] * 16 + plain[i][b] * 4 + plain[i][c]])
			val = false;
 
	for (int i = 0; i < N; i++)
		arr[spotty[i][a] * 16 + spotty[i][b] * 4 + spotty[i][c]] = 0;
 
	return val;
}
 
int main() {
    //setIO("cownomics");
    cin >> N >> M;
    for (int i = 0; i < N; i++){
    	string s; cin >> s;
    	for (int j = 0; j < M; j++){
    		if (s[j] == 'A') spotty[i][j] = 0;
    		if (s[j] == 'C') spotty[i][j] = 1;
    		if (s[j] == 'G') spotty[i][j] = 2;
    		if (s[j] == 'T') spotty[i][j] = 3;
 
    	}
    }
 
    for (int i = 0; i < N; i++){
    	string s; cin >> s;
    	for (int j = 0; j < M; j++){
    		if (s[j] == 'A') plain[i][j] = 0;
    		if (s[j] == 'C') plain[i][j] = 1;
    		if (s[j] == 'G') plain[i][j] = 2;
    		if (s[j] == 'T') plain[i][j] = 3;
    	}
    }
 
    int ans = 0;
    for (int x = 0; x < M; x++)
    	for (int y = x + 1; y < M; y++)
    		for (int z = y + 1; z < M; z++)
    			if (isValid(x, y, z))
    				ans++;
 
    cout << ans << endl;
    return 0;
}

/*
Because there are at most 50 characters in the genome, we can iterate over all 
triplets and determine if each triplet is unique. To do this, we use a trick 
where if we are given two strings of three length consisting of possibly four characters, 
those two strings are only equivalent when (after assigning numeric values to each character), 
16 * first + 4 * second + third are the same value.
*/
