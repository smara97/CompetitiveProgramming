#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
void File() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}
long double srt(ll x,ll y) {
	return sqrt(pow(x, 2) + pow(y, 2));
}
 int main() {
   fast;
   string s;
   cin >> s;
   vector<int>v(s.length() + 1, 0);
   int res = 0;
   for (int i = 1; i < s.length(); i++) {
	   res += bool(s[i] == s[i - 1]);
	   v[i] = res;
   }
   int q; cin >> q;
   while (q--) {
	   int l, r;
	   cin >> l >> r;
	   if (l == r)cout << 1 << endl;
	   else cout << v[r - 1] - v[l - 1] << endl;
   }
		return 0;
}
