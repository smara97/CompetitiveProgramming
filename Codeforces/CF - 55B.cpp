#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
int main()
{
	fast;	
	vector<ll>v(4);
	vector<char>vx(3);
	for (int i = 0; i < 4; i++)cin >> v[i];
	for (int i = 0; i < 3; i++)cin >> vx[i];
	ll res = 1e18, ans = 1e18;
	sort(v.begin(), v.end());
	do {
		ll a, b;
		if (vx[0] == '*')a = v[0] * v[1];
		else a = v[0] + v[1];
		if (vx[1] == '*')b = v[2] * v[3];
		else b = v[3] + v[2];
		if (vx[2] == '*')res = min(res, (a*b));
		else res = min(res, (a + b));
		ll tmp = v[0];
	 	for (int i = 0; i < 3; i++) {
			if (vx[i] == '*')tmp *= v[i + 1];
			else tmp += v[i + 1];
		}
			res = min(res, tmp);
	} while (next_permutation(v.begin(), v.end()));
	cout << res <<  endl;
	return 0;
} 
