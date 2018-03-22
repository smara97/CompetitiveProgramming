#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int sum(ll num) {
	int ret = 0;
	while (num) {
		int mo = num % 10;
		ret += mo, num /= 10;
	}
	return ret;
}
int main() {
	ll n, res = INT_MIN;
	cin >> n;
	ll prv = sqrt(n) - 1e3;
	if (prv < 0)prv = 0;
	for (ll i =prv; i <= sqrt(n) + 1e3; i++) {
		if ((i* (i + sum(i))) == n) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
