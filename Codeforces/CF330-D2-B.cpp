#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
void File() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}
int main() {
	fast;
	int n, m;
	cin >> n >> m;
	bool ad[1001][1001];
	vector<int>vi(n+1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		ad[u][v] = ad[v][u] = 1;
		vi[u]++, vi[v]++;
	}
	vector<pair<int, int>>vp;
	for (int i = 1; i <= n; i++)
		vp.push_back({ vi[i],i });
	sort(vp.begin(), vp.end());
	int root = vp[0].second;
	vector<pair<int, int>>pu;
	for (int i = 1; i <= n; i++) {
		if (i == root)continue;
		 pu.push_back({ i,root });
	}
	cout << pu.size() << endl;
	for (auto e : pu)cout << e.first << ' ' << e.second << endl;
	return 0;
}
