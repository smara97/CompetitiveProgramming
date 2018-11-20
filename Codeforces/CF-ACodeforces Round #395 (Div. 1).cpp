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
	int n; cin >> n;
	vector<pair<int, int>>vp(n - 1);
	int mxnode = 1,mxcol=0;
	vector<int>col(n+1),cunt((int)1e6,0);
	for (int i = 0; i < n - 1; i++)
		cin >> vp[i].first >> vp[i].second;
	for (int i = 1; i <= n; i++)cin >> col[i];
	for (int i = 0; i < n - 1; i++) {
		int u = vp[i].first, v = vp[i].second;
		if (col[u] == col[v])continue;
			cunt[col[u]]++, cunt[col[v]]++;
			if (cunt[col[u]] > mxcol) mxnode = u, mxcol = cunt[col[u]];
			if (cunt[col[v]] > mxcol)mxnode = v, mxcol = cunt[col[v]];
	}
	 bool oko = 1;
	for (int i = 0; i < n - 1; i++) {
		int u = vp[i].first, v = vp[i].second;
		if (u == mxnode || v == mxnode)continue;
		if (col[u] == col[v])continue;
		oko = 0; break;
	}
	if (oko)cout << "YES\n" << mxnode << endl;
	else cout << "NO" << endl;
	m3lsh;
}
