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
int sum(ll num) {
	int ret = 0;
	while (num) {
		ret += (num % 10);
		num /= 10;
	}
	return ret;
}
int main() {
	fast;
	ll a, b;
	cin >> a >> b;
	ll bi = 0, en = a;
	ll res1 = 0, res2 = 0;
	while (bi <= en) {
		ll mid = (bi + en) / 2;
		int ch = sum(mid);
		if ((mid-ch) >= b)res1 = mid, en = mid - 1;
		else bi = mid + 1;
	}
	bi = res1, en = a;
	while (bi <= en) {
		ll mid = (bi + en) / 2;
		int ch = sum(mid);
		if ((mid-ch) >= b)res2 = mid, bi = mid + 1;
		else en = mid - 1;
	}
	if (res1)cout << res2 - res1 + 1 << endl;
	else cout << res1 << endl;
	m3lsh;
}
