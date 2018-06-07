#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
vector<ll>fftime, ltime;
vector < vector<ll>>ad;
vector<ll>cost;
vector<ll>v;
vector<bool>vis;
ll tmm,mn=0,cc=1,cn=0;
ll res = 0;
vector<pair<int, vector<int>>>p;
void scc(int u) {
	fftime[u] = ltime[u] = tmm++;
	v.push_back(u); vis[u] = 1;
	for (int i = 0; i < ad[u].size(); i++) {
		if (fftime[ad[u][i]] == -1)
			scc(ad[u][i]);
		if (vis[ad[u][i]])
			ltime[u] = min(ltime[ad[u][i]], ltime[u]);
	}
	if (fftime[u] == ltime[u]) {
		vector<int>cp;
		while (1) {
			int s = v.back(); v.pop_back();
			cp.push_back(s);
			vis[s] = 0; 
			if (u == s)break;
		}
		p.push_back({ cp.size(),cp });
	}
}
int main() {
	fast;
	int n;
	cin >> n;
	ad = vector<vector<ll>>(n + 1);
	fftime = ltime = vector<ll>(n + 1, -1);
	vis = vector<bool>(n + 1, 0);
	int m;
	cin >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		ad[u].push_back(v);
	}
	tmm = 0;
	for (int i = 1; i <= n; i++) {
		if (fftime[i] == -1) {
			mn = INT_MAX, scc(i);
			v.clear();
		}
	}
	sort(p.rbegin(), p.rend());
	vector<int>pu; pu=p[0].second;
	sort(pu.begin(), pu.end());
	cout << pu.size() << endl;
	for (int i = 0; i < pu.size(); i++)
		cout << pu[i] << ' ';
	cout << endl;
		return 0;;

}
