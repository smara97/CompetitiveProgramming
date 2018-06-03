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
	vector<pair<int, int>>vp(n);
	for (int i = 0; i < n; i++)
		cin >> vp[i].first >> vp[i].second;
	sort(vp.begin(), vp.end());
	ll res = 1;
		pair<int, int>pa = { vp[0].first,vp[0].second };
	for (int i = 0; i < n; i++) {
		if (vp[i].first > pa.second)
			pa = { vp[i].first,vp[i].second }, res++;
		else if (vp[i].second < pa.second)
			pa = { vp[i].first,vp[i].second };
	}
	cout << res << endl;
	return 0;
}
