#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
vector<ll>par;
vector<bool>tk;
bool ad[2001][2001] = { 0 };
set<ll>pu;
int fnd_par(int x) {
	pu.insert(x);
	if (x != par[x])x = fnd_par(par[x]);
	return par[x];
}
int main()
{
	fast;
	int n;
	cin >> n;
	par = vector<ll>(n + 1);
	tk = vector<bool>(n + 1,0);

	for (int i = 1; i <= n; i++) {
		cin >> par[i];
		if (par[i] == -1)par[i] = i;
	}

	for (int i = 0; i < n; i++) {
		int x = par[i + 1];
		if (x != -1) {
			fnd_par(i + 1);
			set<ll>::iterator it = pu.begin();
			while (it != pu.end()) {
				ad[*it][i + 1] = 1; ad[i + 1][*it] = 1;
				it++;
			}
			pu.clear();
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (!tk[i]) {
			res++; tk[i] = 1;
			vector<int>m3aya;
			m3aya.push_back(i);
			for (int j = 1; j <= n; j++) {
				if (!tk[j]) {
					if (!ad[i][j]) {
						bool ok = 1;
						for (int k = 0; k < m3aya.size(); k++) {
							if (ad[j][m3aya[k]]) { ok = 0; break; };
						}
						if (ok)tk[j] = 1, m3aya.push_back(j);
					}
				}
			}
			m3aya.clear();
		}
	}
	cout << res << endl;
	return 0;
}
