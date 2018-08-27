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
int main() {
   fast;
   double n, t, tt, pr;
   cin >> n >> t >> tt >> pr;
   vector<pair<double, ll>>vp;
   for (int i = 1; i <= n; i++) {
	   double a, b; cin >> a >> b;
	   double prv = a*t; prv = ((prv / 100.0) * (100 - pr))+(b*tt);
	   double nxt = b*t; nxt = ((nxt / 100.0)*(100 - pr)) + (a*tt);
	   vp.push_back({ max(prv,nxt),-i });
   }
   sort(vp.rbegin(), vp.rend());
   for (int i = 0; i < n; i++) {
	   cout << -vp[i].second <<' '<< fixed << setprecision(2) << vp[i].first << endl;
   }
   return 0;
}
