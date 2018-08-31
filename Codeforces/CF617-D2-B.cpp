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
   int n;
   cin >> n;
   vector<int>v(n); int fi =-1, la = -1;
   for (int i = 0; i < n; i++) {
	   cin >> v[i];
	   if (v[i]) {
		   if (fi >= 0)la = i;
		   else fi = i;
	   }
   }
   ll res = 1,ze=0;
   if (fi == -1)cout << 0 << endl;
   else {
	   for (int i = fi; i <= la; i++) {
		   if (v[i])res *= (ze + 1), ze = 0;
		   else ze++;
	   }
	   cout << res << endl;
   }
   return 0;
}
