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

ll v[1010];
ll dp[1010][1010];
int dpAux[1010][1010];
int n, k;

int main(){
	int k, n;
	cin >> n >> k;
	v[0] = 0;
	for(int i = 1; i <= k; i++)
		cin >> v[i];
	v[++k] = n;
	k++;

	memset(dp, 0, sizeof dp);
	for(int sz = 1; sz <= k; sz++){
		for(int i = 0; i+sz <= k; i++){
			int j = i+sz-1;
			if(sz <= 2) continue;
			dp[i][j] = 1LL<<60;
			for(int x = i+1; x < j; x++)
				dp[i][j] = min(dp[i][j], dp[i][x] + dp[x][j]);
			dp[i][j] += (v[j]-v[i]);
		}
	}

	cout << dp[0][k-1] << endl;
	return 0;
}