#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
int main()
{
	fast;
	ll n, m, mod = 1e9;
	cin >> n >> m;
	vector<ll>v(n);
	vector<ll>fib(1e7);
	fib[0] = fib[1] = 1;
	for (int i = 2; i <= 1e6 + 5; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < m; i++) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1)v[l - 1] = r;
		else if (t == 2) {
			ll sum = 0;
			for (int j = 0; j <= abs(l - r); j++) {
				sum += (fib[j] * v[l - 1 + j]) % mod;
				sum %= mod;
			}
			cout << sum << endl;
		}
		else {
			int d; cin >> d;
			for (int j = min(l, r) - 1; j <= max(l, r) - 1; j++)
				v[j] += d;
		}
	}
	return 0;
}

	return 0;
}
