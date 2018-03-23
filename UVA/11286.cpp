#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main()
{
	fast;
	int n;
	while (cin >> n) {
		if (!n)break;
		map<vector<int>,int>mp;
		map<ll, int>cn;
		int mx = 0;
		for (int i = 0; i < n; i++) {
			vector<int>su(5);
			for (int j = 0; j < 5; j++)
				cin >> su[j];
			sort(su.begin(), su.end());
			mp[su]++;
			mx = max(mx, mp[su]);
		}
		map<vector<int>, int>::iterator it = mp.begin();
		ll res = 0;
		while (it != mp.end()) {
			res += bool(it->second == mx)*it->second;
			it++;
		}
		cout << res << endl;
	}
	return 0;
}
