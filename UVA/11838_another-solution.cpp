#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
vector<vector<ll>>ad;
vector<ll>ftime, ltime;
vector<bool>vis;
vector<ll>v;
int tme = 0,res=0;
void scc(int u) {
	ftime[u] = ltime[u] = tme++; v.push_back(u);
	vis[u] = 1;
	for (int i = 0; i < ad[u].size(); i++) {
		if (ftime[ad[u][i]]==-1)
			scc(ad[u][i]);
		if(vis[ad[u][i]])
			ltime[u] = min(ltime[u], ltime[ad[u][i]]);
	}
	if (ltime[u] == ftime[u]) {
		res++;
		while (1) {
			int s = v.back();
			v.pop_back();
			vis[s] = 0;
			if (u == s)break;
		}
	}
}
int main() {
  fast; 
  int n, m;
  while (cin >> n >> m) {
	  if (!n && !m)break;
	  res = 0; v.clear();
	  ftime = ltime = vector<ll>(n + 1, -1);
	  ad = vector<vector<ll>>(n + 1);
	  vis = vector<bool>(n + 1, 0);
	  for (int i = 0; i < m; i++) {
		  int u, v, p;
		  cin >> u >> v >> p;
		  ad[u].push_back(v);
		  if (p == 2)ad[v].push_back(u);
	  }
	  for (int i = 1; i <= n; i++) {
		  if (ftime[i] == -1) {
			  scc(i);
		  }
	  }
	  if (res == 1)cout << "1" << endl;
	  else cout << "0" << endl;
  }
	  return 0;
}
