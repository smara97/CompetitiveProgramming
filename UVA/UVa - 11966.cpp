#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
vector<pair<double, double>>vp;
vector<bool>vis;
vector<vector<ll>>ad;
double sqrt(double x, double y, double xx, double yy) {
	return sqrt(pow(abs(x - xx), 2) + pow(abs(y - yy), 2));
}
void dfs(int u) {
	vis[u] = 1;
	for (int i = 0; i < ad[u].size(); i++) {
		if (!vis[ad[u][i]])dfs(ad[u][i]);
	}
}
int main()
{
	fast;
	int tc, cnt = 1;
	cin >> tc;
	while (tc--) {
		double d; int n;
		cin >> n >> d;
		vp = vector<pair<double, double>>(n + 1);
		ad = vector<vector<ll>>(n + 1);
		vis = vector<bool>(n + 1,0);
		for (int i = 1; i <= n; i++)
			cin>>vp[i].first >> vp[i].second;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					if (sqrt(vp[i].first, vp[i].second, vp[j].first, vp[j].second) <= d) {
						ad[i].push_back(j);
					}
				}
			}
		}
		ll res = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				res++, dfs(i);
			}
		}
		cout << "Case " << cnt++ << ": " << res << endl;
	}
	return 0;
}
