#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
vector<ll>par;
vector<ll>rnk;
void merg(int u, int v) {
	if (rnk[u] > rnk[v])par[v] = u;
	else par[u] = v;
	if (rnk[u] == rnk[v])rnk[u]++;
}
int fnd(int u) {
	if (par[u] != u)par[u]=fnd(par[u]);
	return par[u];
}
bool uni(int u, int v) {
	u = fnd(u), v = fnd(v);
	if (u != v) {
		merg(fnd(u), fnd(v));
		return 1;
	}
	return 0;
}
int main()
{
	fast;
	int tc;
	cin >> tc;
	for (int j = 1; j <=tc;j++) {
		int n;
		cin >> n;
		par = vector<ll>(n + 1);
		rnk = vector<ll>(n + 1,0);
		for (int i = 1; i <= n; i++)par[i] = i, rnk[i] = 0;
		string s; int u, v, suc = 0, uns = 0; char c;
		cin.ignore();
		while (1) {
			if(!getline(cin, s) || s.empty())break;
			sscanf(s.c_str(), "%c %d %d", &c, &u, &v);
			if (c == 'c') {
				uni(u, v);
			}
			else {
				if (fnd(u) == fnd(v))suc++;
				else uns++;
			}
		}
		if (j != 1)cout << "\n";
		cout << suc << ',' << uns << "\n";
	}
	return 0;
}
