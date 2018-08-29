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
double dis(int x, int xx, int y, int yy) {
	return double(sqrt(pow(x - xx, 2) + pow(y - yy, 2)));
}
int main() {
   fast;
   int n,m;
   cin >> n>>m;
   vector<int>v(n+1);
   vector<vector<int>>ad(n + 1);
   for (int i = 0; i < m; i++) {
	   int x, y;
	   cin >> x >> y;
	   ad[x].push_back(y);
	   ad[y].push_back(x);
	   v[x]++, v[y]++;
   }
   int res = 0;
   while (1) {
	   queue<int>q;
	   for (int i = 1; i <= n; i++) {
		   if (v[i] == 1)q.push(i);
	   }
	   if (q.empty())break;
	   res++;
	   while (q.size()) {
		   int u = q.front(); q.pop(); v[u] = 0;
		   for (int i = 0; i < ad[u].size(); i++) {
			   v[ad[u][i]]--;
		   }
	   }
   }
   cout << res << endl;
   return 0;
}
