#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
int main() {
	fast;
	int n, m;
	cin >> n >> m;
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		res += (i%5 + m) / 5;
	}
	cout << res << endl;
	return 0;
}
