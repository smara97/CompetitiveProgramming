#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main() {
	fast;
	int n, m;
	while (cin >> n >> m && n && m) {
		map<ll, ll>mp;
		for (int i = 0; i < (m + n); i++) {
			ll x; cin >> x;
			mp[x]++;
		}
		map<ll, ll>::iterator it = mp.begin(); ll res = 0;
		while (it != mp.end()) {
			res += bool(it->second > 1); it++;
		}
		cout << res << endl;
	}
	return 0;
}
