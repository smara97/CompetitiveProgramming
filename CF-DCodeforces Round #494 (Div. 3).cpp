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
set<ll>coin;
int main() {
	fast;
	int n, q;
	cin >> n >> q;
	vector<ll>v(n), cnt(33, 0);
	bool one = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i], one |= bool(v[i] == 1);
		cnt[(int)log2(v[i])]++;
	}
	sort(v.begin(), v.end());
	while (q--) {
		ll x; cin >> x;
		ll mul = 1, res = 0; vector<ll>tmp(32);
		for (int i = 0; i <= 32; i++)tmp[i] = cnt[i];
		for (int i = log2(x) + 1; i >= 0; i--) {
			if (tmp[i] && x) {
				ll dv = (x / (ll(1 << i)));
				dv = min(dv, tmp[i]);
					res += dv;
					x -= (dv*(ll(1 << i)));
				}
			}
		if (x)cout << -1 << endl;
		else cout << res << endl;
	}
	m3lsh;
}
