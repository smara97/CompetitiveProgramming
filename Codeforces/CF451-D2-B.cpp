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
   int n;
   cin >> n;
   vector<ll>v(n);
   for (int i = 0; i < n; i++)cin >> v[i];
   if (is_sorted(v.begin(), v.end()))cout << "yes\n1 1" << endl;
   else {
	   int cnt = 0; int x = 0, y = 0; ll prv = v[0];
	   for (int i = 1; i < n; i++) {
		   if (prv > v[i]) {
			   x = i;
			   while (i < n && prv > v[i])prv = v[i],i++;
			   y = i ;
		   }
		   else prv = v[i];
	   }
	   if (x&&y) {
		   int l = x, r = y;
		   x--, y--;
		   while (x<y)swap(v[x], v[y]), y--, x++;
		   if (is_sorted(v.begin(), v.end()))cout << "yes\n" << l << ' ' << r << endl;
		   else cout << "no" << endl;
	   }
	   else cout << "no" << endl;
   }
		return 0;
}
