#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
vector<vector<ll>>ad;
vector<ll>color;
vector<ll>dis1, dis2;
bool ok = 1;
void pip(ll u, ll col) {
	color[u] = col;
	for (int i = 0; i < ad[u].size(); i++) {
		if (color[ad[u][i]] == color[u])ok = 0;
		if (color[ad[u][i]] == INT_MAX)pip(ad[u][i], 1 - col);
	}
}
int main()
{
	fast;
	int n, e;
	cin >> n >> e;
	ad = vector<vector<ll>>(n + 1);
	color = vector<ll>(n + 1,INT_MAX);
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (color[i] == INT_MAX) {
			pip(i, 0);
			if (!ok) {
				cout << "-1" << endl;
				return 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (color[i]==0)dis1.push_back(i);
		if (color[i]==1) dis2.push_back(i);
	}
	cout << dis1.size() << endl;
	for (int i = 0; i < dis1.size(); i++)
		cout << dis1[i] << ' ';
	cout << endl << dis2.size() << endl;
	for (int i = 0; i < dis2.size(); i++)
		cout << dis2[i] << ' ';
	cout << endl;
	return 0;
}
