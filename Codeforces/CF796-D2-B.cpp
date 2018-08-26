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
   int n, m, k;
   cin >> n >> m >> k;
   vector<int>hol(m);
   for (int i = 0; i < m; i++)cin >> hol[i];
   sort(hol.begin(), hol.end());
   int res = 1;
   while (k--) {
	   int x, y;
	   cin >> x >> y;
	   if (res == x) {
		   if (!binary_search(hol.begin(), hol.end(), res))
			   res = y;
	   }
	   else  if (res == y) {
		   if (!binary_search(hol.begin(), hol.end(), res))
			   res = x;
	   }
   }
   cout << res << endl;
	return 0;
}
