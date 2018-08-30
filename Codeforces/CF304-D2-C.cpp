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
bool ok(int i, int j, int n, int m) {
	return (i >= 0 && i < n&&j >= 0 && j < m);
}
int main() {
   fast;
   int n; cin >> n;
   vector<int>a(n), b(n), c(n);
   for (int i = 0; i < n; i++)
	   a[i] = i, c[i] = n - i - 1;
   map<ll, ll>mp;
   bool ok = 1;
   for (int i = 0; i < n; i++) {
	   ll num = (c[i] + n - a[i]) % n;
	   if (mp[num])ok = 0;
	   else b[i] = (num), mp[b[i]]++;
   }
   if (ok) {
	   for (int i = 0; i < n; i++)cout << a[i] << ' '; cout << endl;
	   for (int i = 0; i < n; i++)cout << b[i] << ' '; cout << endl;
	   for (int i = 0; i < n; i++)cout << c[i] << ' '; cout << endl;
   }
   else cout << -1 << endl;
   return 0;
}
