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
int par[110], rnk[110];
int fnd(int u) {
	if (par[u] != u)par[u] = fnd(par[u]);
	return par[u];
}
void merg(int u, int v) {
	if (rnk[u] < rnk[v])par[u] = v;
	else par[v] = u;
	if (rnk[u] == rnk[v])rnk[u]++;
}
void uni(int u, int v) {
	u = fnd(u), v = fnd(v);
	if (u != v)merg(fnd(u), fnd(v));
}
int main() {
	fast;
	int n; cin >> n;
	vector<pair<int, int>>vp(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> vp[i].first >> vp[i].second;
		rnk[i] = 0; par[i] = i;
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (vp[i].first == vp[j].first)uni(i, j);
			if (vp[i].second == vp[j].second)uni(i, j);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (fnd(i) != fnd(j))res++, uni(i, j);
		}
	}
	cout << res << endl;
	m3lsh;
}
