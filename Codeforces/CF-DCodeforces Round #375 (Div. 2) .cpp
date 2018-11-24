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
char grid[100][100];
bool vis[100][100];
int n, m, k;
vector < pair<int, vector<pair<int, int>>>>vp;
vector<pair<int, int>>pr;
bool valid(int i, int j) {
	return (i >= 1 && i <= n && j >= 1 && j <= m);
}
void solve(int r, int c) {
	vis[r][c] = 1; grid[r][c] = '&';
	for (int i = 0; i < 4; i++) {
		int dx = dix[i] + r;
		int dy = diy[i] + c;
		if (valid(dx, dy)) {
			if (grid[dx][dy] == '.' && !vis[dx][dy])
				solve(dx, dy);
		}
	}
}
void cnt(int r, int c) {
	vis[r][c] = 1; pr.push_back({ r,c });
	for (int i = 0; i < 4; i++) {
		int dx = dix[i] + r;
		int dy = diy[i] + c;
		if (valid(dx, dy) && !vis[dx][dy] && grid[dx][dy]=='.')
			cnt(dx, dy);
	}
}
int main() {
	fast;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> grid[i][j];
	for (int i = 1; i <= n; i++) {
		if (grid[i][1] == '.')
			if(!vis[i][1])
				solve(i, 1);
		if (grid[i][m] == '.')
			if(!vis[i][m])
				solve(i, m);
	}
	
	for (int i = 1; i <= m; i++) {
		if (grid[1][i] == '.')
			if (!vis[1][i])
				solve(1, i);
		if (grid[n][i] == '.')
			if (!vis[n][i])
				solve(n, i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (grid[i][j] == '.') {
				if (!vis[i][j]) {
					pr.clear();
					cnt(i, j);
					vp.push_back({ pr.size(),pr });
				}
			}
		}
	}
		sort(vp.begin(), vp.end());
		int res = 0;
		for (int i = 0; i < max((int)vp.size() - k, 0); i++) {
			for (int j = 0; j < vp[i].second.size(); j++) {
				grid[vp[i].second[j].first][vp[i].second[j].second] = '*';
			}
			res += vp[i].second.size();
		}
		cout << res << endl;
		for (int i = 1; i <= n; i++, cout << endl) {
			for (int j = 1; j <= m; j++) {
				if (grid[i][j] == '&')cout << '.';
				else cout << grid[i][j];
			}
		}


	m3lsh;
}
