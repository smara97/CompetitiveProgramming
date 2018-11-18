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
char maze[1000][1000];
bool vis[1000][1000] = { 0 };
vector<pair<int, int>>vp;
int n, m, k;
bool valid(int i, int j) {
	return (i >= 0 && i < n && j >= 0 && j < m);
}
void dfs(int i, int j) {
	vis[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		int ik = i + dix[k];
		int jk = j + diy[k];
		if (valid(ik, jk)) {
			if (!vis[ik][jk]) {
				if (maze[ik][jk] == '.') dfs(ik, jk);
			}
		}
	}
	if (k && maze[i][j] == '.') {
		maze[i][j] = 'X'; k--;
	}
}
int main() {
	fast;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> maze[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maze[i][j] == '.') {
				if (!vis[i][j]) {
					dfs(i, j);
				}
			}
		}
	}
	for (int i = 0; i < n; i++, cout << endl)
		for (int j = 0; j < m; j++)cout << maze[i][j];
	m3lsh;
}
