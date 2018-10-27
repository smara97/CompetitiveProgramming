#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define m3lsh return 0;
typedef long long ll;
typedef unsigned long long ull;


ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int  dix[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int  diy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int par[30001], rnk[30001];
int fnd(int u) {
	if (par[u] != u)par[u] = fnd(par[u]);
	return par[u];
}
void mer(int u, int v) {
	if (rnk[u] > rnk[v])par[v] = u;
	else par[u] = v;
	if (rnk[u] == rnk[v])rnk[u]++;
}
void uni(int u, int v) {
	u = fnd(u), v = fnd(v);
	if (u != v) {
		mer(fnd(u), fnd(v));
	}
}
int main()
{
	fast;
	int n, m;
	while (cin >> n >> m) {
		if (!n && !m)break;
		for (int i = 0; i <= n; i++)par[i] = i, rnk[i] = 0;
		for (int i = 0; i < m; i++) {
			int x, fi = 0; cin >> x;
			for (int j = 1; j <= x; j++) {
				int xx; cin >> xx;
				if (j == 1)fi = xx;
				else uni(xx, fi);
			}
		}
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res += bool(fnd(i) == fnd(0));
		}
		cout << res+1 << endl;
	}
	m3lsh;
}
