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
		par[v] = u;
	else par[u] = v;
	if (rnk[u] == rnk[v])rnk[u]++;
}
int fnd(int x) {
	if (x != par[x])
		par[x] = fnd(par[x]);
	return par[x];
}
bool uni(int u, int v) {
	u = fnd(u), v = fnd(v);
	if (u == v)return 0;
	else {
		merg(fnd(u), fnd(v));
		return 1;
	}
}
int main() {
   fast;
   int tc;
   cin >> tc;
   while (tc--) {
	   ll n, m;
	   cin >> n >> m;
	   par = rnk = vector<int>(n + 1, 0);
	   for (int i = 1; i <= n; i++)par[i] = i;
	   vector<pair<ll, pair<ll, ll>>>vp;
	   for (int i = 0; i < m; i++) {
		   ll u, v, c;
		   cin >> u >> v >> c;
		   vp.push_back({ c,{u,v} });
	   }
	   sort(vp.begin(), vp.end());
	   vector<pair<ll,pair<ll, ll>>>v;
	   ll sumfi = 0,sumsi = INT_MAX;
	   for (int i = 0; i < vp.size(); i++) {
		   if (uni(vp[i].second.first, vp[i].second.second))
			   v.push_back(vp[i]), sumfi += vp[i].first;
	   }
	   for (int i = 0; i < v.size(); i++) {
		   for (int k = 1; k <= n; k++)par[k] = k, rnk[k] = 0;
		   ll sum = 0,cnt=0;
		   for (int j = 0; j < vp.size(); j++) {
			   if (v[i] == vp[j])continue;
			   if (uni(vp[j].second.first, vp[j].second.second))
				    sum += vp[j].first,cnt++;
		   }
		   if(cnt==n-1)
			sumsi = min(sumsi, sum);
	   }
	   cout << sumfi << ' ' << sumsi << endl;
   }
   return 0;
}
