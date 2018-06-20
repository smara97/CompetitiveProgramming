#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl "\n"
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a*b) / gcd(a, b); }
int f = 0, par[1000] = { -1 };
int cst[100][100] = { 0 };
vector<vector<int>>ad;
int s, t;
void mn(int u, int mnn) {
	if (u == s) {
		f = mnn; return;
	}
	else if (par[u] != -1) {
		mn(par[u], min(mnn, cst[par[u]][u]));
		cst[par[u]][u] -= f; cst[u][par[u]] += f;
	}
}
int main() {
	fast;
	int n, e;
	cin >> n >> e;
	ad = vector<vector<int>>(n + 1);
	cin >> s >> t;
	for (int i = 0; i < e; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		cst[u][v] = c;
	}
	ll res = 0;
	while (1) {
		f = 0;
		int dis[1000] = { -1 };
		dis[s] = 0;
		queue<int>q;
		q.push(s); memset(par, -1, sizeof par);
		memset(dis, -1, sizeof dis);
		dis[s] = 0;
		while (q.size()) {
			int u = q.front(); q.pop();
			if (u == t)break;
			for (int i = 1; i <= n; i++) {
				if (cst[u][i] > 0 && dis[i] == -1)
					dis[i] = dis[u] + 1, par[i] = u, q.push(i);
			}
		}
		mn(t, INT_MAX);
		if (!f)break;
		res += f;
	}
	cout << res << endl;
	return 0;

}
