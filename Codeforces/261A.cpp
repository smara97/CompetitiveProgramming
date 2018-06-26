#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
using namespace std;
typedef long long ll;
int main() {
	fast;
	int m, n;
	cin >> m;
	int mn = INT_MAX;
	vector<int>vm(m);
	for (int i = 0; i < m; i++)cin >> vm[i];
	sort(vm.begin(), vm.end());
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	sort(v.rbegin(), v.rend());
	ll res = 0, ind = 0;
	while (ind < n) {
			int tmp = vm[0];
			while (tmp-- && ind < n)res += v[ind++];
			ind += 2;
	}
	cout << res << endl;
	return 0;
}
