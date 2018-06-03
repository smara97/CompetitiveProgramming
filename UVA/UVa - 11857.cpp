#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
vector<ll>par, rnk;
ll fnd(ll x) {
	if (par[x] != x)par[x] = fnd(par[x]);
	return par[x];
}
void mrg(ll x, ll y) {
	if (rnk[x] > rnk[y])
		par[y] = x;
	else par[x] = y;
	if (rnk[x] == rnk[y])rnk[x]++;
}
bool uni(ll x, ll y) {
	x = fnd(x), y = fnd(y);
	if (x != y) {
		mrg(fnd(x), fnd(y));
		return 1;
	}
	return 0;
}
int main() {
fast;
ll n, m;
while (cin >> n >> m) {
	if (!n && !m)
		break;
	par = vector<ll>(n);
	rnk = vector<ll>(n);
	for (int i = 0; i < n; i++)par[i] = i, rnk[i] = 0;
	vector<pair<ll,pair<ll, ll>>>vp;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		vp.push_back({ c,{u,v} });
	}
	sort(vp.begin(), vp.end());
	ll cnt = 0, res = 0;
	for (int i = 0; i < m; i++) {
		ll u = vp[i].second.first, v = vp[i].second.second;
		ll c = vp[i].first;
		if (uni(u, v)) {
			res = c, cnt++;
		}
	}
	if (cnt == (n - 1))cout << res << endl;
	else cout << "IMPOSSIBLE" << endl;
}
	return 0;
}
