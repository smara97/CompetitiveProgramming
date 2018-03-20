#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main() {
	string s; ll num;
	int n, m;
	cin >> n >> m;
	map<string, ll>mp;
	for (int i = 0; i < n; i++) {
		cin >> s >> num;
		mp[s] = num;
	}
	ll res = 0;
	while (cin >> s) {
		if (s == ".") {
			cout << res << endl;
			res = 0;
		}
		else res += mp[s];
	}
	return 0;
}
