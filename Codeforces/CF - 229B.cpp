#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
int main() {
fast;
int n, m;
cin >> n >> m;
vector<ll>dis(n + 1, 1e16);
priority_queue<pair<ll, ll>, vector<pair<ll,ll>>,greater<pair<ll, ll>>>pq;
vector<vector<pair<ll,ll>>>ad(n + 1);
for (int i = 0; i < m; i++) {
	ll u, v, c;
	cin >> u >> v >> c;
	ad[u].push_back({ c,v });
	ad[v].push_back({ c,u });
}
dis[1] = 0;
pq.push({ 0,1 });
ll res = 0;
vector<vector<ll>>vs(n+1);
for (int i = 1; i <= n; i++) {
	int x;
	cin >> x;
	for (int j = 0; j < x; j++) {
		ll xx; cin >> xx;
		vs[i].push_back(xx);
	}
}
while (pq.size()) {
	ll c = pq.top().first, u = pq.top().second;
	pq.pop();
	if (c > dis[u])continue;
	ll prv = dis[u];
	while (binary_search(vs[u].begin(), vs[u].end(), prv))prv++;
	for (int i = 0; i < ad[u].size(); i++) {
		ll v = ad[u][i].second, d = ad[u][i].first;
		if (prv + d < dis[v]) {
			dis[v] = prv + d;
			pq.push({ dis[v],v });
		}
	}
}
if (dis[n] == 1e16)dis[n] = -1;
cout << dis[n] << endl;
	return 0;
}
