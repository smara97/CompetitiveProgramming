#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
int ad[2001][2001];
int main() {
  fast; 
  int n, m;
  while (cin >> n >> m) {
	  if (!n && !m)break;
	  memset(ad, 0, sizeof ad);
	  for (int i = 0; i < m; i++) {
		  int u, v, p;
		  cin >> u >> v >> p;
		  ad[u][v] = 1;
		  if (p % 2 == 0)ad[v][u] = 1;
	  } for (int k = 1; k <= n; k++)
		  for (int u = 1; u <= n; u++)
			  for (int v = 1; v <= n; v++)
				  if (ad[u][k] && ad[k][v]) ad[u][v] = 1;;
	  bool ok = 1;
	  for (int i = 1; i <= n; i++)
		  for (int j = 1 ; j <= n; j++)
			  ok &= bool(ad[i][j]);
	  if (ok)cout << 1 << endl;
	  else cout << 0 << endl;
  }
	return 0;
}
