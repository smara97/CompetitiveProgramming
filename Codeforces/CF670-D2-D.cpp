#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main()
{
	fast;
	ll n, k;
	cin >> n >> k;
	vector<ll>gr(n), hs(n);
	for (int i = 0; i < n; i++)
		cin >> gr[i];
	for (int i = 0; i < n; i++)
		cin >> hs[i];
	ll b = 1, en = 1e10, res = 0;
	while (b <= en) {
		ll mid = (b + en) / 2;
		bool ok = 1; ll k1 = k;
		for (int i = 0; i < n; i++) {
			ll tmp = (mid*gr[i]); 
			if (tmp > hs[i]) {
				if (abs(tmp - hs[i]) <= k1)k1 -= abs(tmp - hs[i]);
				else {
					ok = 0; break;
				}
			}
		}
		if (ok)res = max(res, mid), b = mid + 1;
		else en = mid - 1;
	}
	cout << res << endl;
	return 0;
}
