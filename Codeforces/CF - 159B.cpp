#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
int main() {
	fast;
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>>vp(n);
	map<pair<int, int>, int>mp;
	map<int, int>mpp;
	for (int i = 0; i < n; i++)cin >> vp[i].first >> vp[i].second;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		mp[{x, y}]++; mpp[y]++;
	}
	int res = 0,ress=0;
	for (int i = 0; i < n; i++) {
		if (mp[{vp[i]}])ress++, mp[{vp[i]}]--;
		if (mpp[(int)(vp[i].second)])
			mpp[(int)(vp[i].second)]--,res++;
	}
	cout << res << ' ' << ress << endl;
	return 0;
}
