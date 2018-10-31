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

// massage to judje " abo to2l dm omk ";
ll occur[100003], val[100003], bas[100004];
struct add {
	int u, v, c;
};
int main()
{
	fast;
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)cin >> bas[i];
	vector<add>v(m);
	for (int i = 0; i < m; i++)cin >> v[i].u >> v[i].v >> v[i].c;
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		occur[x]++; occur[y + 1]--;
	}
	for (int i = 1; i <= m; i++)occur[i] += occur[i - 1];
	for (int i = 0; i < m; i++) {
		val[v[i].u] += (occur[i + 1] * v[i].c);
		val[v[i].v+1]-= (occur[i + 1] * v[i].c);
	}
	for (int i = 1; i <= n; i++)val[i] += val[i - 1];
	for (int i = 1; i <= n; i++)cout << bas[i] + val[i] << ' '; cout << endl;
	m3lsh;
}
