#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
int main() {
	fast;
	ll n, t;
	cin >> n >> t;
	if (t != 10)
		for (int i = 0; i < n; i++)cout << t;
	else {
		if (n == 1)cout << -1;
		else {
			cout << 1; for (int i = 1; i < n; i++)cout << '0';
		}
	}
	cout << endl;
	return 0;
}
