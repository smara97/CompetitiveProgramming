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
vector<int>par, rnk;
double dis(int x, int y, int xx, int yy) {
	return double(sqrt(pow(x - xx, 2) + pow(y - yy, 2)));
}
vector<bool>vis;
void merg(int u, int v) {
	if (rnk[u] > rnk[v])
		par[v] = u,rnk[u]+=rnk[v];
	else par[u] = v,rnk[v]+=rnk[u];
	if (rnk[u] == rnk[v])rnk[u]++;
}
int fnd(int x) {
	return x == par[x] ? x : par[x] = fnd(par[x]);
}
bool uni(int u, int v) {
	u = fnd(u), v = fnd(v);
	if (u == v)return 0;
	else {
		vis[u] = vis[v] = 1;
		merg(fnd(u), fnd(v));
		return 1;
	}
}
int main() {
   fast;
   int tc;
   cin >> tc;
   while (tc--) {
	   if (tc)cout << endl;
	   ll n; cin >> n;
	   par = rnk = vector<int>(n + 1, 0);
	   for (int i = 1; i <= n; i++)par[i] = i;
	   vis = vector<bool>(n + 1, 0);
	   vector<pair<ll, ll>>vp(n + 1);
	   for (int i = 1; i <= n; i++)
		   cin >> vp[i].first >> vp[i].second;
	   vector < pair<double, pair<ll, ll>>>ad;
	   for (int i = 1; i <= n; i++) {
		   for (int j = i + 1; j <= n; j++) {
			   ad.push_back({ dis(vp[i].first,vp[i].second,vp[j].first,vp[j].second),{i,j} });
		   }
	   }
	   sort(ad.begin(), ad.end());
	   int m; cin >> m;
	   int no = 0;
	   for (int i = 0; i < m; i++) {
		   int u, v; cin >> u >> v;
		   if (uni(u, v))no++;
	   }
	   if (no == n-1) {
		   cout << "No new highways need" << endl;
	   }
	   else {
		   vector<pair<int, int>>pu;
		   for (int i = 0; i < ad.size(); i++) {
			   if (uni(ad[i].second.first, ad[i].second.second))
				   pu.push_back({ ad[i].second.first, ad[i].second.second });
		   }
		   for (int i = 0; i < pu.size(); i++)
			   cout << pu[i].first << ' ' << pu[i].second << endl;
	   }
   }
   return 0;
}
