#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
int main()
{
	fast;
	int n;
	cin >> n;
	vector<ll>cnt(1e5 +4,0);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		cnt[x]++;
	}
	ll res = 0;
	for (ll i = 0; i < cnt.size(); i++)cnt[i] *= i;
	for (ll i = 2; i < cnt.size(); i++)
		cnt[i] = max(cnt[i] + cnt[i - 2], cnt[i - 1]);
	cout << cnt.back() << endl;
	return 0;
} 
