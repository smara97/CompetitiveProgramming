#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
int main()
{
	fast;
	int n;
	cin >> n;
	vector < ll>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	ll res = 0,ans=INT_MAX;
	ll a, b = a = 0;
	if (n % 2)a = b = v[n / 2];
	else a = v[n / 2 - 1], b = v[n / 2];
	int mid = n / 2, prv = min(a,b);
	mid -= bool(n % 2 == 0);
	while (mid >= 0) {
		res += bool(v[mid] != prv);
		res += bool(v[n-1-mid] != prv);
		prv--; mid--;
	}
	if (prv < 0)res = INT_MAX;
	ans = min(ans, res);
	res = 0; prv = max(a, b), mid = n / 2;
	mid -= bool(n % 2 == 0);
	while (mid >= 0) {
		res += bool(v[mid] != prv);
		res += bool(v[n - 1 - mid] != prv);
		prv--; mid--;
	}
	if (prv < 0)res = INT_MAX;
	ans = min(ans, res);
	a = v[0], b = v[n - 1];
	mid = 0; prv = min(a, b); res = 0;
	while (mid <n/2) {
		res += bool(v[mid] != prv);
		res += bool(v[n - 1 - mid] != prv);
		prv++; mid++;
	}
	res += bool((n % 2)==1 && prv != v[n / 2]);
	ans = min(ans, res);
	res = 0; prv = max(a, b), mid = 0;
	while (mid <n/2) {
		res += bool(v[mid] != prv);
		res += bool(v[n - 1 - mid] != prv);
		prv++;
		mid++;
	}
	res += bool((n % 2) == 1 && prv != v[n / 2]);
	ans = min(ans, res);
	cout << ans << endl;
	return 0;
}
