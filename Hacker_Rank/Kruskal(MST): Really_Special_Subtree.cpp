#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
vector<ll>par;
vector<ll>rnk;
void st() {
	for (int i = 1; i < par.size(); i++)par[i] = i, rnk[i] = 0;
}
int fnd(int x) {
	if (par[x] != x) 
		par[x]=fnd(par[x]);
	return par[x];
}
void merg(int u, int v) {
	if (rnk[u] > rnk[v])par[v] = u;
	else par[v] = u;
	if (rnk[u] == rnk[v])rnk[u]++;
}
bool uni(int u, int v) {
	u = fnd(u), v = fnd(v);
	if (u != v) {
		merg(fnd(u), fnd(v));
		return 1;
	}
	return 0;
}
int main()
{
	fast;
	int n, m;
	cin >> n >> m;
	rnk = vector<ll>(n + 1);
	par = vector<ll>(n + 1);
	st();
	vector<pair<ll, pair<ll, ll>>>vp;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		vp.push_back({ c,{u,v} });
	}
	sort(vp.begin(), vp.end());
	ll res = 0;
	for (int i = 0; i< vp.size(); i++) {
		if (uni(vp[i].second.first, vp[i].second.second)) {
			res += abs(vp[i].first);
		}
	}
	cout << res << endl;
	return 0;
}
