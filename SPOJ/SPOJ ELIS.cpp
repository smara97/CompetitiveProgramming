#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int main()
{
	fast;
	int n, res = 0, prv = 0, mx = 0;;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < (1 << n ); i++,prv=0,mx=0) {
		for (int j = 0; j < n; j++) {
			if (i&(1 << j)) {
				if (v[j] > prv)
					prv = v[j], mx++;
			}
		}
		res = max(mx, res);
	}
	cout << res << endl;
	return 0;
}
