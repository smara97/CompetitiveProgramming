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
   ll n, k;
   cin >> n >> k;
   vector<ll>po,ng;
   for (int i = 0; i < n; i++) {
	   ll x; cin >> x;
	   if (x >= 0)po.push_back(x);
	   else ng.push_back(x);
   }
   int ind = 0;
   while (ind < ng.size()) {
	   if (k)po.push_back(abs(ng[ind++])),k--;
	   else po.push_back(ng[ind++]);
   }
   sort(po.begin(), po.end());
   ll res = 0;
   if (k && k % 2)po[0] *= -1;
   for (int i = 0; i < po.size(); i++)res += po[i];
   cout << res << endl;
   return 0;
}
