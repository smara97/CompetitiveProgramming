#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
vector<vector<pair<ll, ll>>>ad;
vector<int>par, rnk;
int fnd(int x) {
	if (x != par[x])par[x] = fnd(par[x]);
	return par[x];
}
void mrg(int x, int y) {
	if (rnk[y] < rnk[x])
		par[x] = y,rnk[x]+=rnk[y];
	else par[y] = x,rnk[y]+=rnk[x];
}
bool uni(int x, int y) {
	y = fnd(y);
	x = fnd(x);
	if (x != y) {
		mrg(fnd(x), fnd(y));
		return 1;
	}
	return 0;
}
int main() {
	fast;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		ad = vector<vector<pair<ll, ll>>>(n + 1);
		par = rnk = vector<int>(n + 1, 1);
		for (int i = 0; i <= n; i++)par[i] = i;
		vector<pair<ll, pair<ll, ll>>>vp;
		for (int i = 0; i < m; i++) {
			ll u, v, c;
			cin >> u >> v >> c;
			vp.push_back({ c,{u,v} });
		}
		ll res = 0;
		sort(vp.begin(), vp.end());
		vector<pair<ll, pair<ll, ll>>>mst;
		for (int i = 0; i < vp.size(); i++) {
			int u = vp[i].second.first, v = vp[i].second.second;
			if (uni(u, v)) {
				res += vp[i].first;
				mst.push_back({ vp[i].first,{u,v} });
			}
		}
		ll res1 = INT_MAX;
		for (int i = 0; i < mst.size(); i++) {
			cout << mst[i].first << ' ' << mst[i].second.first << ' ' << mst[i].second.second << endl;
			for (int k = 0; k <= n; k++)par[k] = k, rnk[k] = 1;
			ll mn = 0, nod = 0;
			for (int j = 0; j < vp.size(); j++) {
				if (mst[i] != vp[j]) {
					if (uni(vp[j].second.first, vp[j].second.second))
						mn += vp[j].first, nod++;
				}
			}
			if (nod == (n - 1))
				res1 = min(res1, mn);
		}
		if (res1 == INT_MAX)res1 = res;
		cout << res << ' ' << res1 << endl;
	}
		return 0;;

}
