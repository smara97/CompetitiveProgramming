#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main() {
	ll n;
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, m; bool ok = 0;
		cin >> n >> m;
		vector<ll>bn(n);
		for (int i = 0; i < n; i++)
			cin >> bn[i];
		for (int i = 0; i < (1 << n); i++) {
			ll sum = 0;
			for (int j = 0; j < n; j++) {
				sum += (bool(i&(1 << j))*bn[j]);
			}
			if (sum == m) {
				cout << "Yes\n"; ok = 1;
				break;
			}
		}
		if (!ok)cout << "No\n";
	}
	return 0;
}
