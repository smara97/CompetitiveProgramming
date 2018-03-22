#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main()
{
	fast;
	int s, n;
	cin >> s >> n; vector<pair<int, int>>vp;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vp.push_back({ a,b });
	}
	sort(vp.begin(), vp.end());
	for (int i = 0; i < n; i++) {
		if (s > vp[i].first)s += vp[i].second;
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
