#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
void File() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
double dis(int x, int y, int xx, int yy) {
	return double(sqrt(pow(x - xx, 2) + pow(y - yy, 2)));
}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
int n; vector<pair<int, int>>pos;
void solve(int row) {
	if (row == n) {
		char grid[10][10];
		for (int i = 0; i < n; i++)
			grid[pos[i].first][pos[i].second] = 'Q';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] != 'Q')grid[i][j] = '.';
				cout << grid[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		bool  ok = 1;
		for (int j = 0; j < row; j++) {
			if (pos[j].second == i ||
				pos[j].first + pos[j].second == (row + i) || (pos[j].first - pos[j].second) == (row - i))ok = 0;
		}
		if (ok) {
			pos.push_back({ row,i });
			solve(row + 1);
			pos.pop_back();
		}
	}
}
int main() {
	fast;
	cin >> n;
	solve(0);
	return 0;;
}
