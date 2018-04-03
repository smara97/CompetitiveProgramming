#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
vector<set<ll>>ad(1e6 + 1);
int main()
{
	fast;

	int n, e;
	cin >> n >> e;
	vector<ll>col(n + 1);
	ll ans = 1e7; map<int, bool>tk;
	ll mx = -1;
	for (int i = 1; i <= n; i++) {
		cin >> col[i];
		tk[col[i]] = 1;
		mx = max(mx, col[i]);
	}

	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		if (col[u] != col[v]) {
			ad[col[u]].insert(col[v]);
			ad[col[v]].insert(col[u]);
		}
	}int mn = 0; ans = INT_MIN;
	for (int i = 1; i <= mx; i++) {
		if (tk[i]) {
			if (ad[i].size() > mn || ans == INT_MIN)
				ans = i, mn = ad[i].size();
		}
	}
	cout << ans << endl;
	return 0;
}
