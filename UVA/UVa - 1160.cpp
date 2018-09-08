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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
vector<ll>rnk(1e6, 0), par(1e6, 0);
void intia() {
	for (int i = 0; i < 1e6; i++)par[i] = i, rnk[i] = 0;
}
int fnd(int x) {
	if (par[x] != x)par[x] = fnd(par[x]);
	return par[x];
}
void merg(int x, int y) {
	if (rnk[x] > rnk[y])
		par[y] = x;
	else par[x] = y;
	if (rnk[y] == rnk[x])rnk[y]++;
}
bool uni(int u, int v) {
	u = fnd(u), v = fnd(v);
	if (u != v) {
		merg(fnd(u), fnd(v));
		return 1;
	}
	return 0;
}
int main() {
   fast;
   int a, b,res=0;
   intia();
   while (cin >> a) {
	   if (a == -1) {
		   cout << res << endl;
		   intia(); res = 0;
	   }
	   else {
		   cin >> b;
		   res += (!uni(a, b));
	   }
   }
	return 0;
}
