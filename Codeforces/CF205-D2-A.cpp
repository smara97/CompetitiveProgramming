#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
int main() {
	fast;
	int n; cin >> n;
	map<int, int>mp;
	int mn = INT_MAX; map<int, int>po;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mn = min(mn, x);
		mp[x]++; po[x] = i + 1;
	}
	if (mp[mn] == 1)cout << po[mn] << endl;
	else cout << "Still Rozdil" << endl;
	return 0;
}
