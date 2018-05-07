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
	int n;
	cin >> n;
	map<int, int>mp;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x != 4)mp[x]++;
		res += bool(x == 4);
	}
	if (mp[3] >= mp[1])res += mp[3], mp[1] = 0;
	else res += mp[3], mp[1] -= mp[3];
	mp[1] = mp[1] / 2 + mp[1] % 2;
	mp[1] += mp[2];
	res += ((mp[1]) / 2) + bool(mp[1] % 2);
	cout <<res << endl;
	return 0;

}
