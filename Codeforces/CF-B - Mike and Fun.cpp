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

int main() {
	fast;
	int n, m, q;
	cin >> n >> m >> q;
	int dis[501][501],val[501];
	ll res = 0;
	for (int i = 0; i < n; i++) {
		val[i] = 0; int pai = 0;
		for (int j = 0; j < m; j++) {
			cin >> dis[i][j];
			if (dis[i][j])pai++;
			else pai = 0;
			val[i] = max(pai, val[i]);
		}
	}
	while (q--) {
		int  x, y; cin >> x >> y; x--, y--;
		dis[x][y] = 1 - dis[x][y];
		int pai = 0; val[x] = 0;
		for (int i = 0; i < m; i++) {
			if (dis[x][i])pai++;
			else pai = 0;
			val[x] = max(val[x], pai);
		}
		res = 0;
		for (int i = 0; i < n; i++)res = max(res, ll(val[i]));
		cout << res << endl;
	}
	m3lsh;
}
