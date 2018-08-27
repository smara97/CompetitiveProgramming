#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
void File() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}
int main() {
	fast;
	ll n; cin >> n;
	ll prv = 1, nxt = 10;
	ll res = 0;
	while (1) {
		if (n >= prv && n < nxt) {
			res += ((n - prv + 1)*log10(nxt));
			break;
		}
		else {
			res += ((nxt - prv)*log10(nxt));
		}
		prv *= 10, nxt *= 10;
	}
	cout << res << endl;
	return 0;
}
