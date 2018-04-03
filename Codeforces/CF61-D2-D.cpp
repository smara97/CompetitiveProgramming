#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
vector < vector<pair<ll, ll>>>ad;
vector<bool>vis;
 bool ok = 0;
ll solve(ll u) {
	vis[u] = 1;
	ll res = 0;
	for (int i = 0; i < ad[u].size(); i++) {
		int v = ad[u][i].first;
		if (!vis[v]) {
			res = max(res, ad[u][i].second+ solve(v));
		}	
	}
	return  res;
}
int main() {
	fast;
	int n;
	cin >> n;
	ad = vector< vector<pair<ll, ll>>>(n+1);
	vis = vector<bool>(n + 1, 0);
	ll mx = 0;
	for (int i = 0; i < n - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c; mx += (2 * c);
		ad[u].push_back({ v,c });
		ad[v].push_back({ u,c });
	}
	cout << mx-solve(1) << endl;
	return 0;
}
