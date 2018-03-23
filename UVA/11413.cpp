#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main()
{
	fast;
	int n, m;
	while (cin >> n >> m) {
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		ll b = 1, en = 1e9, res = 0;
		while (b <= en) {
			ll mid = (b + en) / 2, co = 1,temp=mid,nu=0;
			for (int i = 0; i < n; i++) {
				if (temp >= v[i])temp -= v[i],nu++;
				else {
					temp = mid;
					if (temp >= v[i])co++, temp -= v[i], nu++;
				}
			}
			if (nu == n) {
				if (co > m)b = mid + 1;
				else if (co <= m)en = mid-1,res=mid;
			}
			else b = mid + 1;
		}
		cout << res << endl;
	}
	return 0;
}
