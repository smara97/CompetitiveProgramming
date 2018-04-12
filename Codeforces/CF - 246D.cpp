#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
int main()
{
	fast;
	ll n, m,mx=0;
	cin >> n >> m;
	vector<ll>col(n + 1);
	vector<bool>take(1e6, 0);
	for (int i = 1; i <= n; i++)
		cin >> col[i], mx = max(mx, col[i]), take[col[i]] = 1;

	vector<set<ll>>ad(mx+2);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (col[u] != col[v]) {
			ad[col[u]].insert(col[v]);
			ad[col[v]].insert(col[u]);
		}
	}
	ll res = INT_MIN,color=1;
	for (int i = 1; i <= mx; i++) {
		if (take[i]) {
			if (res < ad[i].size())
				res = max(res, (ll)ad[i].size()), color = i;
		}
	}
		
	cout << color << endl;
	return 0;
}
