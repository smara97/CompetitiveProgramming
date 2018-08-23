#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
void File() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}
vector < vector<ll>>ad;
int n, s, t;
ll bfs(int u) {
	queue<int>q;
	vector<int>dis(n + 1,INT_MAX);
	vector<bool>vis(n + 1, 0);
	vis[u] = 1;
	q.push(u); dis[u] = 0;
	while (q.size()) {
		int uu = q.front(); q.pop();
		vis[uu] = 1;
		for (int i = 0; i < ad[uu].size(); i++) {
			if (!vis[ad[uu][i]]) {
				dis[ad[uu][i]] = dis[uu] + 1;
				q.push(ad[uu][i]);
			}
		}
	}
	if(dis[s]!=INT_MAX)
		return dis[s];
	return 1e16;
}
 int main() {
   fast;
   cin >> n >> s >> t;
   ad = vector<vector<ll>>(n + 1);
   for (int i = 1; i <= n; i++) {
	   int x; cin >> x;
	   ad[x].push_back(i);
   }
   bool st = 0, e = 0;
   ll res = 1e16; int ind =1;
   for (int i = 0; i < ad[t].size(); i++) {
	   ll u = ad[t][i];
	   res = min(bfs(u) + 1, res);
   }
   if (s == t)cout << 0 << endl;
   else if (res == 1e16)cout << -1 << endl;
   else cout << res << endl;
		return 0;
}
