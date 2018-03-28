#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int a[5]; bool ook = 0;
bool solve (ll sum, int ind) {
	if (ind == 5) {
		if (sum == 23) return 1;
		return false;
	}
	bool op = solve(sum + a[ind], ind + 1);
		op|=solve(sum - a[ind], ind + 1);
		op|=solve(sum * a[ind], ind + 1);
		return op;
}
int main()
{
	fast;
	while (1) {
		for (int i = 0; i < 5; cin >> a[i],i++);
		sort(a, a + 5);
		if (count(a, a + 5, 0) == 5)break;
		ook = 0;
		do {
			if (solve(a[0], 1)) {
				cout << "Possible" << endl;
				ook = 1;
				break;
			}
		} while (next_permutation(a, a + 5));
		if (!ook)cout << "Impossible" << endl;
	}
	return 0;
}
