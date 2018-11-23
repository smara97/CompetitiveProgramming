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
vector<vector<int>>ad(100);
vector<int>state(100,0),parent(100, 0),ap(100, 0),low(100, 0),num(100, 0);
int cycle = 0,countert=0,root,child=0;
void AP(int u) {
	low[u] = num[u] = countert++;
	state[u] = 1;
	for (int i = 0; i < ad[u].size(); i++) {
		if (state[ad[u][i]] == 0) {
			if (u == root)child++;
				parent[ad[u][i]] = u;
			AP(ad[u][i]);
			low[u] = min(low[u], low[ad[u][i]]);
			if ( root!=u && low[ad[u][i]] >= num[u])ap[u] = 1;
		}
		else {
			if (parent[u] != ad[u][i]) {
				low[u] = min(low[u], num[ad[u][i]]);
			}
		}
	}
}

/*
0--- 1 ---2
   / | \
  3	 4---5
*/


int main() {
	fast; 
	int n, e; cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int u, v; cin >> u >> v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}
	int res = 0;
	for (int i = 1; i <=n; i++) {
		if (state[i] == 0) {
			root = i; child = 0; AP(i);
			if (child > 1)ap[i] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
		if (ap[i])cout << i << ' ',res++;
	cout << res << endl;
	m3lsh;
}
