#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define m3lsh return 0;
#define PI (double)3.14159265359
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int  dix[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int  diy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

int gr[1001][1001];
ll dis[1001][1001];
int main() {
	fast;
	int r, c;
	while (cin >> r >> c) {
		int s1, s2, e1, e2;
		for (int i = 0; i <= r; i++)
			for (int j = 0; j <= c; j++)
				dis[i][j] = -1;
		if (!r && !c)break;
		int bo; cin >> bo;
		while (bo--) {
			int nm, ro; cin >> ro >> nm;
			for (int i = 0; i < nm; i++) {
				int x; cin >> x; dis[ro][x] = 1e8;
			}
		}

		cin >> s1 >> s2 >> e1 >> e2;
		dis[s1][s2] = 0;
		queue<pair<int, int>>q;
		q.push({ s1,s2 });
		while (q.size()) {
			int u = q.front().first, v = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int dx = dix[i] + u;
				int dy = diy[i] + v;
				if (dx >= 0 && dx <= r && dy >= 0 && dy <= c) {
					if (dis[dx][dy]<0) {
							q.push({ dx,dy });
							dis[dx][dy] = dis[u][v] + 1;
					}
				}
			}
		}
		cout << dis[e1][e2] << endl;
	}
	m3lsh;
}
