#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
void File() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
double dis(int x, int y, int xx, int yy) {
	return ll(sqrt(pow(x - xx, 2) + pow(y - yy, 2)));
}
int main() {
   fast;
   int n, m;
   cin >> n >> m;
   vector<int>vi(n, 0);
   for (int i = 0; i < m; i++) {
	   int u, v,c;
	   cin >> u >> v >> c;
	   u--, v--;
	   vi[u] += c, vi[v] -= c;
   }
   ll res = 0;
   for (int i = 0; i < n; i++) {
	   if (vi[i] < 0)res += abs(vi[i]);
   }
   cout << res << endl;
   return 0;
}
