#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef pair<int, int> ii;

#define MAXN 10
int arr[MAXN] = {1, 2, 3, 4};
int C[MAXN][MAXN], dp[MAXN][MAXN];

int main(){
	int n = 4;
	int k = 2;

	for(int i = 0; i < n; i++){
		int soma = 0;
		for(int j = i; j < n; j++){
			soma += arr[j];
			C[i][j] = soma*(j-i+1);
		}
	}

	for(int i = 0; i < n; i++)
		dp[0][i] = 0;
	for(int i = 0; i < n; i++)
		dp[1][i] = C[0][i];

	for(int i = 2; i <= k; i++)
		for(int j = 0; j < n; j++){
			dp[i][j] = 1<<30;
			for(int l = 0; l < j; l++)
				dp[i][j] = min(dp[i][j], dp[i-1][l] + C[l+1][j]);
		}

	cout << dp[k][n-1] << endl;
	return 0;
}