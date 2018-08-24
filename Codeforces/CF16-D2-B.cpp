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
   ll n, m;
   cin >> n >> m;
   vector<pair<ll, ll>>v(m);
   for (int i = 0; i < m; i++)
	   cin >> v[i].second >> v[i].first;
   sort(v.rbegin(), v.rend());
   ll res = 0;
   for (int i = 0; i < m && n>0; i++) {
	   res += (min(n, v[i].second)*v[i].first);
	   n -= min(v[i].second,n);
   }
   cout << res << endl;
		return 0;
}
