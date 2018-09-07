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
vector<ll>par, rnk;
int fnd(int x) {
	if (x != par[x])par[x] = fnd(par[x]);
	return par[x];
}
void merg(int x, int y) {
	if (rnk[x] > rnk[y])
		par[y] = x;
	else par[x] = y;
	if (rnk[y] == rnk[x])rnk[x]++;
}
bool uni(int x, int y) {
	x = fnd(x), y = fnd(y);
	if (x != y) {
		merg(fnd(x), fnd(y));
		return 1;
	}
	return 0;
}
int main() {
   fast;
   ll n, m;
   int tc = 1;
   while (cin >> n >> m) {
	   if (!n && !m)break;
	   par = rnk = vector<ll>(n + 1, 0);
	   for (int i = 0; i <= n; i++)par[i] = i;
	   ll res = n;
	   vector<bool>tk(n + 1, 0);
	   for (int i = 0; i < m; i++) {
		   int u, v; cin >> u >> v;
		   if ((uni(u, v))) res--;
	   }
	   cout <<"Case "<<tc++<<": " <<res << endl;
   }
   return 0;
}
