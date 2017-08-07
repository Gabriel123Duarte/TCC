#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef pair<int, int> ii;

#define MAXN 20
int v[] = {2, 5, 3, 7, 11, 8};
int bit[MAXN];
int dp[MAXN];

void update(int x, int v){
	for(; x < MAXN; x+=x&-x)
		bit[x] = max(bit[x], v);
}

int get(int x){
	int ans = 0;
	for(; x; x-=x&-x)
		ans = max(ans, bit[x]);
	return ans;
}

int lis(int n){
	int ans = 0;

	for(int i = 0; i < n; i++){
		dp[i] = 1+get(v[i]);
		update(v[i], dp[i]);
		ans = max(ans, dp[i]);
	}

	return ans;
}

int main(){
	cout << lis(6) << endl;
	return 0;
}