#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main()
{
	fast;
	int n, m;
	cin >> n >> m;
	vector<ll>v(n);
	ll sum = 0;
	for (int i = 0; i < n; i++)
		cin >> v[i], sum += v[i];
	vector<ll>vm(m);
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		vm[i] = v[x - 1];
		sum -= v[x - 1];
	}
	sort(vm.rbegin(), vm.rend());
	for (int i = 0; i < m; i++) {
		if (sum >=vm[i] )sum += sum;
		else sum += vm[i];
	}
	cout << sum << endl;
	return 0;
}
