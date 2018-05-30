#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
int main()
{
	fast;
	int n, x;
	cin >> n; ll ans = 0;
	vector<ll>v(n + 1, 0);
	for (int i = 0; i < n; i++)
		cin >> x, v[i + 1] = v[i] + x;
	for (int i = 1; i < n; i++)
		ans += bool(v[i] == (v[n] - v[i]));
	cout << ans << endl;
	return 0;
}
