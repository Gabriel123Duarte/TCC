/*input
17 3
2 6 8
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

#define MAXN 1010
#define inf 99999999

int v[MAXN];
int dp[MAXN][MAXN];
int opt[MAXN][MAXN];

int knuthOptimization(int n, int k){
	// Adicionado os elementos extras
	v[0] = 0;
	v[++k] = n;
	k++;

	for(int tam = 1; tam <= k; tam++){
		for(int i = 0; i+tam <= k; i++){
			int j = i+tam-1;
			if(j-i <= 1){
				dp[i][j] = 0;
				opt[i][j] = i;
				continue;
			}
			dp[i][j] = inf;
			for(int x = opt[i][j-1]; x <= opt[i+1][j]; x++){
				if(dp[i][x] + dp[x][j] + v[j]-v[i] < dp[i][j]){
					dp[i][j] = dp[i][x] + dp[x][j] + v[j]-v[i];
					opt[i][j] = x;
				}
			}
		}
	}
	return dp[0][k-1];
}

int main(){
	int k, n;
	cin >> n >> k;
	for(int i = 1; i <= k; i++)
		cin >> v[i];

	cout << knuthOptimization(n, k) << endl;	
	return 0;
}