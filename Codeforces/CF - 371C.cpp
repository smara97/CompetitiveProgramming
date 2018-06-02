#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
int main()
{
	fast;	
	string s;
	cin >> s;
	ll nb = 0, ns = 0, nc = 0;
	for (int i = 0; i < s.length(); i++) {
		ns += bool(s[i] == 'S');
		nb += bool(s[i] == 'B');
		nc += bool(s[i] == 'C');
	}
	ll hb, hs, hc;
	cin >> hb >> hs >> hc;
	ll rb, rs, rc, tot;
	cin >> rb >> rs >> rc;
	cin >> tot;
	ll b = 0, en = 1e14, res = 0;
	while (b <= en) {
		ll mid = (b + en) / 2;
		ll tmp = 0;
		if ((mid*nb) > hb)tmp += abs((mid*nb) - hb)*rb;
		if ((mid*ns) > hs)tmp += abs((mid*ns) - hs)*rs;
		if ((mid*nc) > hc)tmp += abs((mid*nc) - hc)*rc;
		if (tmp > tot)en = mid - 1;
		else res = mid, b = mid + 1;
	}
	cout << res << endl;
	return 0;
} 
