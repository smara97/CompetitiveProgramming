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
	return double(sqrt(pow(x - xx, 2) + pow(y - yy, 2)));
}
struct cont {
	int x, y, r;
};
int main() {
   fast;
   int a, b, aa, bb;
   cin >> a >> b >> aa >> bb;
   if (a > aa)swap(a, aa);
   if (b > bb)swap(b, bb);
   int m; cin >> m;
   vector<cont>v(m);
   for (int i = 0; i < m; i++) 
	   cin >> v[i].x >> v[i].y >> v[i].r;
   ll res = 0;
   for (int i = a; i <= aa; i++) {
	   for (int j = b; j <= bb; j++) {
		   if (a == i || i == aa || b == j || j == bb) {
			   bool ok = 0;
			   for (int k = 0; k < m; k++) {
				   if (dis(i, j, v[k].x, v[k].y) <= v[k].r) {
					   ok = 1; break;
				   }
			   }
			   res += bool(!ok);
		   }
	   }
   }
   cout << res << endl;
   return 0;
}
