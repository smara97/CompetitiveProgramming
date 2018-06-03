#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
int main()
{
	fast;
	int n, m;
	cin >> n >> m;
	vector<string>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	map<pair<string, string>, bool>mp;
	for (int i = 0; i < m; i++) {
		string x, y; cin >> x >> y;
		mp[{x, y}] = mp[{y, x}] = 1;
	}
	vector<string>pu;
	for (ll i = 0; i < (1 << n); i++) {
		vector<string>vs;
		for (int j = 0; j < n; j++) {
			if (i&(1 << j)) {
				bool ok = 1;
				for (int k = 0; k < vs.size(); k++) {
					if (mp[{v[j], vs[k]}]) {
						ok = 0; break;
					}
				}
				if (ok)vs.push_back(v[j]);
			}
		}
		if (vs.size() > pu.size())pu = vs;
	}
	sort(pu.begin(),pu.end());
	cout << pu.size() << endl;
	for (auto e : pu)cout << e << endl;
	return 0;
} 
