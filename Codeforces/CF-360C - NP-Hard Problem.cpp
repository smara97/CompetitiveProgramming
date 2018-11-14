#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define m3lsh return 0;
typedef long long ll;
typedef unsigned long long ull;


ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int  dix[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int  diy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
vector<vector<ll>>v(100001);
int col[100001] = {-1};
bool ok = 1;
void dfs(int u) {
	for (int i = 0; i < v[u].size(); i++) {
		if (col[v[u][i]] == -1)col[v[u][i]] = 1 - col[u],dfs(v[u][i]);
		else {
			if (col[u] == col[v[u][i]]) {
				ok = 0; return;
			}
		}
	}
}
int main() {
	fast;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, vv;
		cin >> u >> vv;
		v[u].push_back(vv);
		v[vv].push_back(u);
	}
	memset(col, -1, sizeof col);
	for (int i = 1; i <= n; i++) {
		if (col[i] == -1 && v[i].size()) {
			col[i] = 0;
			dfs(i);
		}
	}
	vector<int>fi, se;
	if (ok) {
		for (int i = 1; i <= n; i++) {
			if (col[i] == 1)fi.push_back(i);
			else if(col[i]==0)se.push_back(i);

		}
		cout << fi.size() << endl;
		for (auto f : fi)cout << f << ' '; cout << endl;
		cout << se.size() << endl;
		for (auto f : se)cout << f << ' '; cout << endl;
	}
	else cout << -1 << endl;
	m3lsh;
}
