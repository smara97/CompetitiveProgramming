#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
vector<vector<int>>ad(200);
vector<bool>vis(200);
void dfs(int u) {
	vis[u] = 1;
	for (int i = 0; i < ad[u].size(); i++)if (!vis[ad[u][i]])
		dfs(ad[u][i]);
}
void cnt(int u, int n, int m) {
	for (int i = 1; i <=n; i++) {
		if (!vis[i] || n != m) {
			cout << "NO" << endl; return;
		}
	}
	cout << "FHTAGN!" << endl;
}
int main()
{
	fast;
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int u, v; cin >> u >> v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
	dfs(1), cnt(1,n,m);
	return 0;

}
