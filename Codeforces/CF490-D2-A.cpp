#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
int main() {
	fast;
	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	ll res = min(count(v.begin(), v.end(), 1), min(count(v.begin(), v.end(), 3), count(v.begin(), v.end(), 2)));
	cout << res << endl;
	while (res--) {
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < n; i++) {
			if (!a && v[i] == 1)a = i + 1,v[i]=-1;
			if (!b && v[i] == 2)b = i + 1,v[i]=-1;
			if (!c && v[i] == 3)c = i + 1,v[i]=-1;
		}
		cout << a << ' ' << b << ' ' << c << endl;
	}
	return 0;
}
