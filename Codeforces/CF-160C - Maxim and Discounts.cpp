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
	int m, n;
	cin >> m;
	int mn = 1e6;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		mn = min(x, mn);
	}
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	sort(v.rbegin(), v.rend());
	ll res = 0;
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (j<mn && i < n)res += v[i],i++,j++;
		i ++;
	}
	cout << res << endl;
	m3lsh;
}
