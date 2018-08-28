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
   ll n, m, k;
   cin >> n >> m >> k;
   map<ll, ll>mp;
   ll res = 0,mo= 1073741824;
   for (int i = 1; i <= n; i++) {
	   for(int j=1;j<=m;j++){
		   for (int p = 1; p <= k; p++) {
			   ll num = i*p*j;
			   if (mp[num])res += mp[num];
			   else {
				   int div = 0;
				   for (int u = 1; u*u <= num; u++) {
					   if (num%u == 0) {
						   div++;
						   if (num / u != u)div++;
					   }
				   }
				   mp[num] = div;
				   res += div;
			   }
			   res %= (mo);
		   }
	   }
   }
   cout << res << endl;
   return 0;
}
