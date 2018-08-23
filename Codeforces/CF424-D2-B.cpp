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
   ll n, s;
   cin >> n >> s;
   s= 1000000 - s;
   vector<pair<long double,ll>>v(n);
   for (int i = 0; i < n; i++) {
	   ll x, y, k; cin >> x >> y >> k;
	   v[i] = { srt(x, y),k };
   }
   sort(v.begin(), v.end());
   ll sum = 0; long double res = 0;
   for (int i = 0; i < n && sum<s; i++) {
	   sum += v[i].second;
	   res = v[i].first;
   }
   if (sum < s)cout << -1 << endl;
   else cout << fixed << setprecision(7) << res << endl;
		return 0;
}
