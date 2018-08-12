#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
int main() {
	fast;
	ll n, k;
	cin >> n >> k;
	ll od = 0;
	if (n % 2)od = n / 2 + 1;
	else od = n / 2;
	if (k <= od)cout << (2 * k) - 1 << endl;
	else cout << (2 * (k - od)) << endl;
	return 0;
}
