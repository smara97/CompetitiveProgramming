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
   int n;
   cin >> n;
   vector<ll>v(n);
   vector<vector<ll>>ad(1e4);
   map<ll, ll>mp;
   int ind = 0;
   for (int i = 0; i < n; i++) cin >> v[i],mp[v[i]]++;
   sort(v.begin(), v.end());
   for (int i = 1; i <= 1e3; i++) {
	   if (mp[i]) {
		   ind = 0;
		   while (mp[i]--)ad[ind++].push_back(i);
	   }
   }
   ll res = 0;
   for (int i = 0; i < 1e3; i++) {
	   if (ad[i].size())res += ad[i].size() - 1;
   }
   cout << res << endl;
		return 0;
}
