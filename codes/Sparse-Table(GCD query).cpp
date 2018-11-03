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
int n, tmp[1000], sp[1000][20];
void build() {
	for (int i = 0; i < n; i++)sp[i][0] = tmp[i];
	for (int j = 1; j <=log2(n); j++) {
		for (int i = 0; (i + (1 << j) - 1) < n; i++) {
			sp[i][j] = gcd(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int gc(int u, int v) {
	int j = log2(v - u + 1);
	return (gcd(sp[u][j], sp[v - (1 << j) + 1][j]));
}
int main()
{
	fast;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> tmp[i];
	build();
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		cout << gc(u, v) << endl;
	}
	m3lsh;
}
