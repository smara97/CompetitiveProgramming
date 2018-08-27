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
	int n; cin >> n;
	vector<ll>v(n+1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i <= n; i++)
		v[i] += v[i - 1];
	int q; cin >> q;
	while (q--) {
		ll x; cin >> x;
		int ind = lower_bound(v.begin(), v.end(), x) - v.begin();
		cout << ind << endl;
	}
	return 0;
}
