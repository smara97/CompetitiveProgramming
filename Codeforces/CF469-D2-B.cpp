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
double dis(int x, int xx, int y, int yy) {
	return double(sqrt(pow(x - xx, 2) + pow(y - yy, 2)));
}
int main() {
   fast;
   int p, q, t, tt;
   cin >> p >> q >> t >> tt;
   vector<pair<int, int>>vp(p),vq(q);
   for (int i = 0; i < p; i++)cin >> vp[i].first >> vp[i].second;
   for (int i = 0; i < q; i++)cin>>vq[i].first >> vq[i].second;
   ll res = 0;
   while (t <= tt) {
	   bool ok = 0;
	   for (int i = 0; i < q && !ok; i++) {
		   int x = vq[i].first + t, y = vq[i].second + t;
		   for (int j = 0; j < p && !ok; j++) {
			   if (x >= vp[j].first && x <= vp[j].second)ok = 1;
			   else if (x <= vp[j].first && y >= vp[j].first)ok = 1;
		   }
	   }
	   res += bool(ok);
	   t++;
   }
   cout << res << endl;
   return 0;
}
