#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main() {
	fast;
	ll n;

	while (cin >> n&&n) {
		multiset<ll>ms;
		for (ll i = 0; i < n; i++) {
			ll x; cin >> x;
			ms.insert(x);
		}
		multiset<ll>::iterator it = ms.begin(), it1 = ms.end(); it1--;
		while (it != ms.end()) {
			if (it == it1)cout << *it << endl;
			else cout << *it << ' '; it++;
		}
	}
	

	return 0;
}
