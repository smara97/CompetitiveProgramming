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
int main() {
   fast;
   ll n, a, b;
   cin >> n >> a >> b;
   for (int i = 0; i < n; i++) {
	   ll x; cin >> x;
	   ll num = (a*x) / b;
	   ll be = 0, en = 1e9,res=0;
	   while (be <= en) {
		   ll mid = (be + en) / 2;
		   ll tmp = (a*mid) / b;
		   if (tmp > num)en = mid - 1;
		   else if (tmp == num)res = x - mid, en = mid - 1;
		   else be = mid + 1;
	   }
	   cout << res << ' ';
   }
   cout << endl;
   return 0;
}
