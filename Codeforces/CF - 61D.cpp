#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
vector < vector<pair<ll, ll>>>ad;
vector<bool>vis;
ll dfs(ll u) {
	vis[u] = 1;
	ll ret = 0;
	for (int i = 0; i < ad[u].size(); i++) {
		if (!vis[ad[u][i].first]) {
			ret = max(ret, dfs(ad[u][i].first) + ad[u][i].second);
		}
	}
	return ret;
}
int main()
{
	fast;
	ll n,sum=0;
	cin >> n;
	ad = vector<vector<pair<ll, ll>>>(n + 1);
	vis = vector<bool>(n + 1, 0);
	for (int i = 0; i < n - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		sum += (c * 2);
		ad[u].push_back({ v,c });
		ad[v].push_back({ u,c});
	}
	cout << sum - dfs(1);
	return 0;
}
