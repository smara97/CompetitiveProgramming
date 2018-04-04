#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
int main()
{
	fast;
	ll n, m;
	while (cin >> n >> m) {
		vector<ll>v(n);
		for (ll i = 0; i < n; i++)
			cin >> v[i];
		map<pair<ll, ll>, ll>mp; map<ll, ll>occ;
		for (ll i = 0; i < n; i++) {
			occ[v[i]]++;
			mp[{occ[v[i]], v[i]}] = i + 1;
		}
		for (ll i = 0; i < m; i++) {
			ll u, v;
			cin >> u >> v;
			cout << mp[{u, v}] << endl;
		}
	}
	
	return 0;
}
