#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
vector<ll>fftime, ltime;
vector < vector<ll>>ad;
vector<ll>cost;
vector<ll>v;
vector<bool>vis;
ll tmm,mn=0,cc=1,cn=0;
ll res = 0;
void scc(int u) {
	fftime[u] = ltime[u] = tmm++;
	v.push_back(u); vis[u] = 1;
	for (int i = 0; i < ad[u].size(); i++) {
		if (fftime[ad[u][i]] == -1)
			scc(ad[u][i]);
		if (vis[ad[u][i]])
			ltime[u] = min(ltime[ad[u][i]], ltime[u]);
	}
	if (fftime[u] == ltime[u]) {
		mn = INT_MAX; 
		ll cnt = 0;
		while (1) {
			int s = v.back(); v.pop_back();
			vis[s] = 0; 
			if (mn > cost[s])
				mn = cost[s], cnt = 1;
			else if (mn == cost[s])cnt++;
			if (u == s)break;
		}
		if(cnt>1)
			cc *= (cnt);
		cn %= (ll(1e9 + 7));
		res += mn;
	}
}
int main() {
	fast;
	int n;
	cin >> n;
	ad = vector<vector<ll>>(n + 1);
	fftime = ltime = vector<ll>(n + 1, -1);
	cost = vector<ll>(n + 1);
	vis = vector<bool>(n + 1, 0);
	for (int i = 1; i <= n; i++)cin >> cost[i];
	int m;
	cin >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		ad[u].push_back(v);
	}
	tmm = 0;
	for (int i = 1; i <= n; i++) {
		if (fftime[i] == -1) {
			mn = INT_MAX, scc(i);
			v.clear();
		}
	}
	cout << res<<' '<<cc%((ll)1e9+7) << endl;
		return 0;;

}
