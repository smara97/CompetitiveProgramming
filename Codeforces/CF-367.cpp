#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
int main() {
	fast;
	int n;
	cin >> n;
	vector<ll>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	sort(v.begin(), v.end());
	int q;
	cin >> q;
	while (q--) {
		ll x; cin >> x;
		ll up = upper_bound(v.begin(), v.end(),x) - v.begin();
		cout << up << endl;
	}
		return 0;;

}
