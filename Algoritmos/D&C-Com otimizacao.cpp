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
#define inf 99999999
int arr[MAXN] = {10, 12, 18, 26, 26, 150};
//int arr[MAXN] = {1, 2, 3, 4};
int C[MAXN][MAXN], dp[MAXN][MAXN];

void solve(int i, int jInicio, int jFim, int optInicio, int optFim){
	if(jInicio > jFim)
		return;
	
	int mid = (jInicio + jFim) / 2;
	dp[i][mid] = inf;
	int opt = -1;

	for(int l = optInicio; l <= min(optFim, mid); l++){
		if(dp[i-1][l] + C[l+1][mid] < dp[i][mid]){
			dp[i][mid] = dp[i-1][l] + C[l+1][mid];
			opt = l;
		}
	}

	solve(i, jInicio, mid-1, optInicio, opt);
	solve(i, mid+1, jFim, opt, optFim);
}

int divideAndConquer(int n, int k){
	// Calculo da funcao custo O(n^2)
	for(int i = 0; i < n; i++){
		int soma = 0;
		for(int j = i; j < n; j++){
			soma += arr[j];
			C[i][j] = soma*(j-i+1);
		}
	}

	// Casos base
	for(int i = 0; i < n; i++)
		dp[0][i] = 0;
	for(int i = 0; i < n; i++)
		dp[1][i] = C[0][i];

	for(int i = 2; i <= k; i++)
		solve(i, 0, n-1, 0, n-1);

	return dp[k][n-1];
}

int main(){
	cout << divideAndConquer(6, 3) << endl;
	return 0;
}