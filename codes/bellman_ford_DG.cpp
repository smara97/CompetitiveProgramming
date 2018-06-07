#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
struct edge {
	int u, v, c;
};
int main() {
	fast;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector < vector<pair<int, int>>>vp(n+1);
		vector<ll>dis(n+1, 1e9);
		for (int i = 0; i < m; i++) {
			int u, v, c;
			cin >> u >> v >> c;
			vp[u].push_back({ v,c });
		}
		dis[1] = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < vp[j].size(); k++) {
					dis[vp[j][k].first] = min(dis[vp[j][k].first], vp[j][k].second + dis[j]);
				}
			}
		}
		for (int i = 1; i <= n; i++)
			cout << dis[i] << endl;
	}
		return 0;;

}
