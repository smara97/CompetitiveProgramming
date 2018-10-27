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
int par[1000001], rnk[1000001];
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
		mer(fnd(u), fnd(v));
			return 1;
	}
	return 0;
}
int main()
{
	fast;
	int n, e,tc=1;
	while(cin>>n>>e){
		if (!n)break;
		for (int i = 1; i <= n; i++)rnk[i] = 1, par[i] = i;
		int res = n;
		while (e--) {
			int u, v;
			cin >> u >> v;
			if (uni(u, v))res--;
		}
		cout << "Case "<<tc++<<": "<<res << endl;
	}
	m3lsh;
}
