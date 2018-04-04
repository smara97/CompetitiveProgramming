#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
vector<vector<ll>>ad;
vector<bool>vis;
int res = 0,n;
void dfs(int u) {
	vis[u] = 1;
	for (int i = 0; i < ad[u].size(); i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < ad[j].size(); k++) {
				if (ad[u][i] == ad[j][k]) {
					if (!vis[j])dfs(j);
				}
			}
		}
	}
}
int main()
{
	fast;
	int lan;
	cin >> n >> lan;
	vis = vector<bool>(n+1, 0);
	ad = vector<vector<ll>>(n + 1);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		for (int j = 0; j < x; j++) {
			int v; cin >> v;
			ad[i].push_back(v);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && ad[i].size())res++, dfs(i);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ad[i].size() == 0) {
			if (res <= 1)ans++;
			else ans += (res), res = 1;
		}
	}
	ans += bool(res > 1)*(res-1);
	cout << ans << endl;
	return 0;
}
