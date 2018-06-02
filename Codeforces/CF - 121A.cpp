#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
vector<ll>luc;
void luck(ll num) {
	if (num > 1e9)return;
	num *= 10;
	luc.push_back(num+4);
	luck(num + 4);
	luc.push_back(num+7);
	luck(num + 7);
}
int bin(ll num) {
	ll b = 0, en = luc.size() - 1, indl = 0;
	while (b <= en) {
		ll mid = (b + en) / 2;
		if (luc[mid] >= num)indl = mid, en = mid - 1;
		else b = mid + 1;
	}
	return indl;
}
int main()
{
	fast;
	ll l, r; cin >> l >> r;
	luck(0);
	sort(luc.begin(), luc.end());
	ll res = 0,prv=l;
	ll indl = bin(l), indr = bin(r);
	for (int i = indl; i <= indr; i++) {
		ll b = l, en = r, nxt;
		while (b <= en) {
			ll mid = (b + en) / 2;
			ll ban = bin(mid);
			if (ban <= i)b = mid + 1,nxt=mid;
			else en = mid - 1;
		}
		res += (nxt - prv+1)*luc[i];
		prv = nxt + 1;
	}
	cout << res << endl;
	return 0;
} 
