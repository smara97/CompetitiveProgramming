#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
vector<vector<ll>>ad;
vector<ll>pr;
vector<bool>vis;
priority_queue<ll>pp, pi;
void solve(int u) {
	vis[u] = 1;
	pp.push(pr[u]); pi.push(-u);
	for (int i = 0; i < ad[u].size(); i++) {
		if (!vis[ad[u][i]])solve(ad[u][i]);
	}

}
int main()
{
	fast;
	int n, k;
	cin >> n >> k;
	pr = vector<ll>(n + 1);
	ad = vector<vector<ll>>(n + 1);
	vis = vector<bool>(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> pr[i];
	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
	vector<ll>ans(n+1);
	for (int i= 1; i <= n; i++) {
		if (!vis[i]) {
			solve(i);
			while (pp.size()) {
				int in = -pi.top();
				ans[in] = pp.top();
				pi.pop(); pp.pop();
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
