#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
int main() {
	fast;
	ll n, m;
	cin >> n >> m;
	vector<ll>v(n), vm(m);
	for (int i = 0; i < n; i++)cin >> v[i];
	for (int i = 0; i < m; i++)cin >> vm[i];
	ll b = 0, en = 1e16, res = 0;
	while (b <= en) {
		ll mid = (b + en) / 2;
		vector<bool>vis(n + 1,0);
		bool bg = 0; int ind = 0;
		for (int i = 0; i < m; i++) {
			ll prv = vm[i]-mid,nxt=mid+vm[i];
			while (ind < n && prv <= v[ind] && nxt>=v[ind])
				vis[ind++] = 1;
		}
		for (int i = 0; i < n; i++)
			if (!vis[i])bg = 1;
		if (bg)b = mid + 1;
		else res = mid, en = mid - 1;
	}
	cout << res << endl;
	return 0;
}
