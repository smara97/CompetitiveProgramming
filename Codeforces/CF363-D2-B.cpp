#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
void File() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}
int main() {
	fast;
	int n, k;
	cin >> n >> k;
	vector<ll>v(n),vv(n);
	for (int i = 0; i < n; i++)cin >> v[i],vv[i]=v[i];
	for (int i = 1; i < n; i++)v[i] += v[i - 1];
	ll res = 0,ind=0, mn = INT_MAX;
	for (int i = k - 1; i < n; i++,ind++) {
		if ((v[i] - v[ind] + vv[ind]) < mn)
			res = ind, mn = (v[i] - v[ind] + vv[ind]);
	}
	cout << res+1 << endl;
	return 0;
}
