#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
vector<vector<ll>>ad;
vector<bool>vis(1e3);
void dfs(int u,int node) {
	for (int i = 0; i < ad[u].size(); i++) {
		if (!vis[ad[u][i]])vis[ad[u][i]] = 1, dfs(ad[u][i],node);
	}
}
int main()
{
	fast;
	int node;
	while (cin >> node) {
		if (!node)break;
		ad = vector<vector<ll>>(node + 1);
		int ray7;
		while (cin >> ray7) {
			if (!ray7)break;
			int lmen;
			while (cin >> lmen) {
				if (!lmen)break;
				ad[ray7].push_back(lmen);
			}
		}
		int kam;
		cin >> kam;
			for (int i = 0; i < kam; i++) {
				int ebda; cin >> ebda;
				dfs(ebda, node);

				int put = 0; vector<ll>inacsses;
				for (int j = 1; j <= node; j++) {
					if (!vis[j])put++, inacsses.push_back(j);
					else vis[j] = 0;
				}
				cout << put;
				for (int j = 0; j < inacsses.size(); j++) {
					cout << ' ' << inacsses[j];
				}
				cout << endl;
			}
	}
	return 0;
}
