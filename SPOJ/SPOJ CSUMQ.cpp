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
   int n;
   cin >> n;
   vector<ll>v(n),vv(n);
   for (int i = 0; i < n; i++)cin >> v[i]; vv[0] = v[0];
   for (int i = 1; i < n; i++)vv[i] += vv[i - 1]+v[i];
   int q; cin >> q;
   while (q--) {
	   int l, r;
	   cin >> l >> r;
	   cout << vv[r] - vv[l]+v[l] << endl;
   }
   return 0;
}
