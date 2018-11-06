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
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m; cin >> n >> m;
		char dis[200][200];
		int dislr[200][200] , disud[200][200];
		for (int i = 0; i < 200; i++)
			for (int j = 0; j < 200; j++)
				dislr[i][j] = disud[i][j] = 500;
		vector<pair<int, int>>vp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> dis[i][j];
				if (dis[i][j] == '1')vp.push_back({ i,j });
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int mn = 555;
				for (int k = 0; k < vp.size(); k++) {
					mn = min(abs(i - vp[k].first) + abs(vp[k].second - j), mn);
				}
				cout << mn << ' ';
			}
			cout << endl;
		}
	}
	m3lsh;
}
