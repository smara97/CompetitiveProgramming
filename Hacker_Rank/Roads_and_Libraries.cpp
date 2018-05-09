#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
vector<bool>vis;
vector<vector<ll>>ad;
int tk = 0;
void dfs(int u) {
	vis[u] = 1; tk++;
	for (int i = 0; i < ad[u].size(); i++) {
		if (!vis[ad[u][i]])dfs(ad[u][i]);
	}
}
int main()
{
	fast;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, ci, cp;
		cin >> n >> m >> ci >> cp;
		vis = vector<bool>(n + 1, 0);
		ad = vector < vector<ll>>(n + 1);
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			ad[u].push_back(v);
			ad[v].push_back(u);
		}
		ll res = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				dfs(i);
				res += ci;
				tk--;
				res += min(ci, cp)*tk;
				tk = 0;
			}
		}
		cout << res << endl;
	}
	return 0;
}
