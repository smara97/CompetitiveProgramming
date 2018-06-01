#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
int main()
{
	fast;
	int tc;
	cin >> tc;
	int cnt = 1;
	while (tc--) {
		int n;
		cin >> n;
		vector<ll>v(n);
		for (int i = 0; i < n; i++)cin >> v[i];
		ll res = 0, b = 0, en = 1e15;
		while (b <= en) {
			ll mid = (b + en) / 2;
			ll prv = 0,tmp=mid;
			for (int i = 0; i < n; i++) {
				if (tmp < (v[i] - prv))tmp=INT_MIN;
				else if (tmp == (v[i] - prv))tmp--;
				prv = v[i];
			}
			if (tmp >= 0)res = mid, en = mid - 1;
			else b = mid + 1;
		}
		cout <<"Case "<<cnt++<<": " <<res << endl;
	}
	return 0;
}
