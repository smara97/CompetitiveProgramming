#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
int main() {
	fast;
	ll n;
	while (cin >> n) {
		if (!n)break;
		ll x = 0, y = 0; bool ok = 0;
		for (ll i = 1; i <= 100 && !ok; i++) {
			ll temp = (pow(i, 3) + n);
			ll b = 1, en = 150;
			while (b <= en && !ok) {
				ll mid = (b + en) / 2;
				ll po = pow(mid, 3);
				if (po == temp)y = mid,ok=1;
				else if (po > temp)en = mid - 1;
				else b = mid + 1;
			}
			if (ok)x = i;
		}
		if (!x || !y)cout << "No solution" << endl;
		else cout << max(x,y) << ' '<<min(y,x) << endl;
	}
	return 0;
}
