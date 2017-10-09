/*input
4 5
1 3 8 10
4 5
1 3 8 10
*/

#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef pair<int, int> ii;

#define MAXN 1000100
#define inf 99999999
int v[MAXN];
int dp[MAXN];

int sq(int x){
	return x*x;
}

int cht(int n, int c){
	// Caso base
	dp[0] = 0;
	
	for(int i = 1; i <= n; i++){
		dp[i] = inf;
		for(int j = 1; j <= i; j++)
			dp[i] = min(dp[i], dp[j-1] + sq(v[j]-v[i]) + c);
	}
	return dp[n];
}

int main(){
	int n, c;
	cin >> n >> c;
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	cout << cht(n, c) << endl;
	return 0;
}