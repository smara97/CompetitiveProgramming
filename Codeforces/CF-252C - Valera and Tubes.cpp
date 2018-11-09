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
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>>v(k);
	int ro = 1, col = 1;
	bool mins = 0;
	for (int i = 0; i < k - 1; i++) {
		v[i].push_back({ ro,col });
		if (!mins) {
			col++;
			if (col > m) {
				col = m, ro++, mins = 1;
				v[i].push_back({ ro,col });
				col--;
			}
			else v[i].push_back({ ro,col }),col++;
			if (col > m) {
				col = m, ro++, mins = 1;
			}
		}
		else {
			col--;
			if (col <= 0) {
				ro++, col = 1, mins = 0; v[i].push_back({ ro,col }), col++;
			}
			else v[i].push_back({ ro,col }),col--;
			if (col <= 0) {
				ro++, col = 1, mins = 0;
			}
		}
	}
	for (int i = ro; i <= n; i++) {
		if (mins) {
			while (col > 0) {
				v[k - 1].push_back({ i, col }); col--;
			}
			mins = 0; col = 1;
		}
		else {
			while (col <= m) {
				v[k - 1].push_back({ i, col }); col++;
			}
			col = m;
			mins = 1;
		}
	}
	for (int i = 0; i < k; i++) {
		cout << v[i].size() << ' ';
		for (int j = 0; j < v[i].size(); j++)cout << v[i][j].first << ' ' << v[i][j].second << ' ';
		cout << endl;
	}
	m3lsh;
}
