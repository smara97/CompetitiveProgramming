#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main()
{
	fast;
	int n, q;
	int cnt = 1;
	while (cin >> n >> q) {
		if (!n && !q)break;
		cout << "CASE# " << cnt++ << ":" << endl;
		map<int, int>mp;
		vector<int>v(n);
		for (int i = 0; i < n; i++) 
			cin >> v[i];
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++) {
			if (!mp[v[i]])mp[v[i]] = i + 1;
		}
		for (int i = 0; i < q; i++) {
			int x; cin >> x;
			if (mp[x])
				cout << x<<" found at "<<mp[x] << endl;
			else cout << x<<" not found" << endl;
		}
	}
	return 0;
}
