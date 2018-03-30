#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main() {

	fast;
	ll l, n;
	while (cin >> l >> n) {
		if (!l)break;
		priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
		for (int i = 0; i < n; i++) {
			int x, dis; cin >> x >> dis;
			pq.push({ x - dis,-x - dis });
		}
		ll sum = 0; bool ok = 0;
		while (sum < l && pq.size()) {
			ll mx = INT_MIN;
			while (pq.size()) {
				if (pq.top().first <= sum) {
					mx = max(mx, abs(pq.top().second));
					pq.pop(); 
				}
				else break;
			}
			if (mx!=INT_MIN )sum = mx, n--;
			else break;

		}
		if (sum >= l)cout << n  << endl;
		else cout << -1 << endl;
	}
	return 0;
}
