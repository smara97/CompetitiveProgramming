#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define m3lsh return 0;
typedef long long ll;
typedef unsigned long long ull;


ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int  dix[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int  diy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

// massage to judje " abo to2l dm omk ";
bool vis[1001];
vector<vector<int>>ad;

void dfs(int u) {
	vis[u] = 1;
	for (int i = 0; i <(int) ad[u].size(); i++) {
		int v = ad[u][i];
		if (!vis[v])dfs(v);
	}
}

int main(){
	fast;
	int n, m;
	cin >> n >> m; 
	vector<int>lan(n + 1);
	vector<vector<int>>v(m + 1);
	ad = vector<vector<int>>(n + 1);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x; lan[i] += x;
		for (int j = 0; j < x; j++) {
			int u; cin >> u; 
			v[u].push_back(i);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < (int)v[i].size(); j++) {
			for (int k = j + 1; k < (int)v[i].size(); k++) {
				ad[v[i][k]].push_back(v[i][j]);
				ad[v[i][j]].push_back(v[i][k]);
			}
		}
	}
	int res = 0,cc=0;
	for (int i = 1; i <= n; i++) {
		if (!lan[i])res++;
		else if (!vis[i])dfs(i), cc++;
	}
	if(cc)
		res += (cc - 1);
	cout << res << endl;
	m3lsh;
}
