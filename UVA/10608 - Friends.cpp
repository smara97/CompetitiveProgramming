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
double dis(int i, int j, int ii, int jj) {
	return sqrt(pow(i - ii, 2) + pow(j - jj, 2));
}
ll par[30001], rnk[30001], fri[30001];

int fnd(int u) {
	if (par[u] != u)par[u] = fnd(par[u]);
	return par[u];
}
void mer(int u, int v) {
	if (rnk[u] > rnk[v])
		par[v] = u;
	else par[u] = v;
	if (rnk[u] == rnk[v])rnk[u]++;
}
bool uni(int u, int v) {
	u = fnd(u), v = fnd(v);
	if (u != v) {
		u = fnd(u), v = fnd(v);
		fri[u] = fri[v] = (fri[u] + fri[v]);
		mer(u, v);
			return 1;
	}
	return 0;
}
int main()
{
	fast;
	int t; cin >> t;
	while (t--) {
		int n, e; cin >> n >> e; 
		for (int i = 1; i <= n; i++)par[i] = i, rnk[i] = 1,fri[i]=1;
		ll res = 0;
		for (int i = 0; i < e; i++) {
			int u, v; cin >> u >> v;
			uni(u, v);
		}
		for (int i = 1; i <= n; i++)res = max(res, fri[i]);
		cout << res << endl;
	}
	m3lsh;
}
