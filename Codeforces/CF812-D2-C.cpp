#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main()
{
	fast;
	ll n, s;
	cin >> n >> s;
	vector<ll>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	ll k = 0, m = 0,be=1,en=n;
	while (be <= en) {
		ll mid = (be + en) / 2;
		multiset<ll>ms;
		for (int i = 0; i < n; i++) {
			ms.insert((v[i] + (i + 1)*mid));
		}
		multiset<ll>::iterator it = ms.begin();
		ll sum = 0,temp=mid;
		while (it != ms.end() && temp--) {
			sum += *it; it++;
		}
		if (sum <= s) {
			k = mid; m = sum;
			be = mid + 1;
		}
		else en = mid - 1;
	}
	cout << k << ' ' << m << endl;
	return 0;
}
