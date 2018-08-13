#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
int main() {
	fast;
	int t; cin >> t;
	int cnt = 1;
	while (t--) {
		int n; cin >> n;
		vector<ll>v(n);
		for (int i = 0; i < n; i++)cin >> v[i];
		ll res = 0, b = 0, en=10;
		while (b <= en) {
			ll mid = (b + en) / 2;
			ll tmp = mid, prv = 0;
			for (int i = 0; i < n; i++) {
				if ((v[i] - prv) > tmp)tmp=-1;
				else if (v[i] - prv == tmp)tmp--;
				prv = v[i];
			}
			if (tmp >= 0)res = mid,en=mid-1;
			else b = mid + 1;
		}
		cout << "Case " << cnt++ << ": ";
		cout << res << endl;
	}
	return 0;
}
