#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
struct st {
	int a, b, c;
};
int main()
{
	fast;
	int n, m;
	cin >> n >> m;
	int adj[100][100] = { 0 };
	vector<bool>in(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
		in[u] = in[v] = 1;
	}
	vector < st >v;
	vector<bool>tk(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i!= j) {
				if (adj[i][j] && !tk[i] && !tk[j]) {
					int cnt = 0;
					for (int k = 1; k <= n; k++) {
						if (k != i && k != j && !tk[k]) {
							if(adj[k][j] && adj[i][k]) {
								tk[i] = tk[j] = tk[k] = 1;
								v.push_back({ i,j,k });
							}
							else cnt++;
						}
						else cnt++;
					}
					if (cnt == n) {
						for (int k = 1; k <= n; k++) {
							if (!tk[k] && !in[k]) {
								v.push_back({ i, j, k });
								tk[i] = tk[j] = tk[k] = 1;
								break;
							}
						}
					}
				}
			}
		}
	}
	vector<int>vs;
	for (int i = 1; i <= n; i++) {
		if (!in[i] && !tk[i])vs.push_back(i);
		if (vs.size() == 3) {
			v.push_back({ vs[0],vs[1],vs[2] }); vs.clear();
		}
	}
	if ((n / 3) == v.size()) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i].a <<' '<< v[i].b <<' '<< v[i].c << endl;
	}
	else cout << -1 << endl;
	return 0;
} 
