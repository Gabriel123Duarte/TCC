/*input
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

#define MAXN 10
#define inf 99999999
int v[MAXN] = {0, 1, 3, 8, 10};
int dp[MAXN];
int A[MAXN], B[MAXN];
int tam, ponteiro;

int quadrado(int x){
	return x*x;
}

void adicionarLinha(int a, int b){
	while(tam >= 2 && (B[tam-2] - B[tam-1]) * (a-A[tam-1]) >= (B[tam-1]-b) * (A[tam-1]-A[tam-2]))
		tam--;
	A[tam] = a;
	B[tam] = b;
	tam++;
}

int consultar(int x){
	ponteiro = min(ponteiro, tam-1);
	while(ponteiro+1 < tam && A[ponteiro+1]*x+B[ponteiro+1] <= A[ponteiro]*x + B[ponteiro])
		ponteiro++;
	return A[ponteiro]*x + B[ponteiro];
}


int cht(int n, int c){
	// Inicializando a pilha do Convex Hull Trick
	ponteiro = tam = 0;

	// Caso base
	dp[0] = 0;
	adicionarLinha(-2*v[1], quadrado(v[1]));
	for(int i = 1; i <= n; i++){
		dp[i] = consultar(v[i]) + quadrado(v[i]) + c;
		if(i < n)
			adicionarLinha(-2*v[i+1], quadrado(v[i+1])+dp[i]);
	}
	return dp[n];
}

int main(){
	cout << cht(4, 5) << endl;
	return 0;
}