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
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>>v(n + 1);
	vector<ll>dil(n + 1), dir(n + 1), dim(n + 1), dito(n + 1);
	for (int i = 1; i <= n; i++) {
		int l; cin >> l;
		for (int j = 0; j < l; j++) {
			int x; cin >> x;
			v[i].push_back(x);
		}
		ll sml = 0, smr = 0, tmp = 0, tot = 0,mx=INT_MIN;
		for (int j = 0; j < l; j++) {
			tot += v[i][j];
			tmp += v[i][j];
			sml = max(sml, tot);
			mx = max(tmp, mx);
			if (tmp < 0)tmp = 0;
		}
		tot = 0;
		for (int j = l - 1; j >= 0; j--) {
			tot += v[i][j];
			smr = max(tot, smr);
		}
		dir[i] = smr; dil[i] = sml; 
		dito[i] = tot;dim[i] = mx;
	}
	ll res = INT_MIN, prv=0;
	for (int i = 0; i < m; i++) {
		int l; cin >> l;
		res = max(res, dim[l]);
		if (prv!=0)res = max(res, prv + dil[l]);
		prv = max((ll)0,max(dir[l], dito[l] + prv));
	}
	cout << res << endl;
	m3lsh;
}
