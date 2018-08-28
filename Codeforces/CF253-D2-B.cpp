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
  // File();
   int n; cin >> n;
   vector<ll>v(n);
   for (int i = 0; i < n; i++)cin >> v[i];
   sort(v.begin(), v.end());
   vector<int>up(n),dow(n);
   map<int, int>dd, uu;
   int p1 = 0, p2 = n - 1;
   int res = 0;
   while(p1<p2) {
	   int b = p1 + 1, en = p2,ri=p2;
	   while (b <= en) {
		   int mid = (b + en) / 2;
		   if (v[mid] > ((v[p1] * 2)))en = mid - 1, ri = mid;
		   else b = mid + 1;
	   }
	   if (ri != p2)
		   ri = p2 - ri + 1;
	   else {
		   if (v[p1] * 2 < v[p2])ri = p2 - ri + 1;
		   else ri = 0;
	   }
	   b = p1, en = p2 - 1; int lf = p1;
	   while (b <= en) {
		   int mid = (b + en) / 2;
		   if ((v[mid] * 2) < v[p2])lf = mid, b = mid + 1;
		   else en = mid - 1;
	   }
	   if(lf!=p1)
		lf = lf - p1+1;
	   else {
		   if (v[p1] * 2 < v[p2])lf -= p1 + 1;
		   else lf = 0;
	   }
	   if (!ri && !lf)break;
	   if (ri > lf)p1++, res++;
	   else p2--, res++;
   }
   cout << res << endl;
   return 0;
}
