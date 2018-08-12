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
	ll sum = 0, res = 0;
	for (int i = 0; i < n; i++)cin >> v[i],sum+=v[i];
	int t, s;
	cin >> t >> s;
	if (s > t)swap(t, s);
	while (s != t)res += v[s++-1];
	cout << min(res, sum - res) << endl;
	return 0;
}
