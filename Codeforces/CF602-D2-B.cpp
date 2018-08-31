#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
void File() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
double dis(int x, int y, int xx, int yy) {
	return ll(sqrt(pow(x - xx, 2) + pow(y - yy, 2)));
}
int main() {
   fast;
   int n;
   cin >> n;
   vector<ll>v(n);
   for (int i = 0; i < n; i++)cin >> v[i];
   ll l = 0, r = 0, p = 0, p2 = 0;
   ll mn = 1e7, mx = -1e7;
   set<ll>ms; map<ll, ll>mp;
   mp[v[p]] ++; ll res = 0;
   while (p <= p2 && p < n && p2 < n) {
	   ms.insert(v[p2]);
	   ms.insert(v[p]);
	   mn = *ms.begin(); set<ll>::iterator it = ms.end();
	   it--; mx = *it;
	   if (abs(mn - mx) <= 1) {
		   res = max(res, p2 - p + 1); p2++;
		   if (p2 < n)mp[v[p2]]++;
	   }
	   else {
		   mp[v[p]]--;
		   if (!mp[v[p]])ms.erase(v[p]);
		   p++;
	   }
   }
   cout << res << endl; 
   return 0;
}
