#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
int main() {
	fast;
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>>vp(n);
	for (int i = 0; i < n; i++)cin >> vp[i].first, vp[i].second = i + 1;
	sort(vp.begin(), vp.end());
	ll sum = 0;
	vector<int>pu;
	for (int i = 0; i < n && sum<k; i++) {
		if ((sum + vp[i].first) <= k)
			sum += vp[i].first,pu.push_back(vp[i].second);
	}
	cout << pu.size() << endl;
	for (auto e : pu)cout << e << ' '; cout << endl;
	return 0;
}
