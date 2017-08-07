#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fst first
#define snd second
#define debug(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef pair<int, int> ii;

int mochila(){
    int valor[] = {60, 100, 120};
    int peso[]  = {10, 20, 30};
    int capacidade = 50, n = 3;

    int dp[2][capacidade + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= capacidade; j++){
            if(!i || !j)
                dp[i&1][j] = 0;
            else if(peso[i - 1] <= j)
                dp[i&1][j] = max(valor[i-1] + dp[~i&1][j - peso[i-1]], dp[~i&1][j]);
            else
                dp[i&1][j] = dp[~i&1][j];
        }
    }
    return dp[n&1][capacidade]; 
}

int main(){
	

    cout << mochila() << endl;
	return 0;
}