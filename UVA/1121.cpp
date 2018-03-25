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
	while (cin >> n >> s) {
		ll p1 = 0, p2 = 0;
		vector<ll>v(n+2);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		ll sum = 0, res = INT_MAX;
		while (p2 <= n) {
			if (sum < s)sum += v[p2], p2++;
			else {
				while (sum >= s) {
					res = min(res, p2 - p1);
					sum -= v[p1]; p1++;
				}
			}
		}
		if (res == INT_MAX)res = 0;
		 cout << res << endl;
	}
	return 0;
}
