#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main()
{
	fast;
	ll n, q;
	while (cin >> n) {
		vector<ll>v(n+1);
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		v[0] = -1;
		sort(v.begin(), v.end());
		cin >> q;
		while (q--) {
			int x; cin >> x;
			vector<ll>::iterator it, itt;
			it = lower_bound(v.begin(), v.end(), x);
			itt = upper_bound(v.begin(), v.end(), x);
			it--;
			if (*it == -1)cout << 'X' << ' ';
			else cout << *it<<' ';
			if (itt == v.end()) cout << 'X' << endl;
			else {
				cout << *itt << endl;
			}
		}
	}
	return 0;
}
