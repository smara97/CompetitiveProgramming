#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
int main() {
	fast;
	int m;
	cin >> m;
	vector<int>v(m);
	ll sum = 0;
	for (int i = 0; i < m; i++)cin >> v[i], sum += v[i];
	int x, y; cin >> x >> y;
	ll res = 0, num = 0;
	for (int i = 0; i < m; i++) {
		num += v[i];
		if (num >= x && num <= y && (sum - num) >= x && (sum - num) <= y)res = i;
	}
	cout << res+bool(res)*2 << endl;
	return 0;
}
