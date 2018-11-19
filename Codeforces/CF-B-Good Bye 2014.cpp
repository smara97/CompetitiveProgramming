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
vector<vector<int>>ad(400);
vector<bool>vis(400, 0);
	vector<int>v(400);
vector<int>ind;
vector<int>per;
void dfs(int u) {
	vis[u] = 1; per.push_back(v[u]);
	ind.push_back(u);
	for (int i = 0; i < ad[u].size(); i++) {
		if (!vis[ad[u][i]])
			dfs(ad[u][i]);
	}
}
int main() {
	fast;
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '1') {
				ad[i].push_back(j + 1);
				ad[j + 1].push_back(i);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			per.clear(); ind.clear();
			dfs(i);
			sort(per.begin(), per.end());
			sort(ind.begin(), ind.end());
			for (int j = 0; j < per.size(); j++) {
				v[ind[j]] = per[j];
			}
		}
	}
	for (int i = 1; i <= n; i++)cout << v[i] << ' '; cout << endl;
	m3lsh;
}
