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
int n;
int sp[1000][20],tmp[1000];// sp[size of tmp][log(size of tmp])
void build() {
	for (int i = 0; i < n; i++)sp[i][0] = tmp[i];
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; (i + (1 << j) - 1) < n; i++) {
			if (sp[i][j - 1] < sp[i + (1 << (j-1)) ][j - 1])sp[i][j] = sp[i][j - 1];
			else sp[i][j] = sp[i + (1 <<(j-1))][j - 1];
		}
	}
}
int mn(int u, int v) {
	int j = (v - u + 1);
	j = log2(j);
	if (sp[u][j] < sp[v - (1 << j) + 1][j])return sp[u][j];
	else return sp[v - (1 << j) + 1][j];
}
int main()
{
	fast;
	 cin >> n;
	for (int i = 0; i < n; i++)cin >> tmp[i];
	build();
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int u, v; cin >> u >> v;
		cout << mn(u, v) << endl;
	}
	m3lsh;
}
