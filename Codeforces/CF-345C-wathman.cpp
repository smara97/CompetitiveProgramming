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

int main()
{
	fast;
	int n; cin >> n;
	map<ll, ll>mpx, mpy;
	map<pair<ll, ll>,ll>mppa;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		mpx[x]++, mpy[y]++;
		mppa[{x, y}]++;
	}
	ll res = 0;
	for (auto e : mpx)res += (e.second*(e.second - 1) / 2);
	for (auto e : mpy)res += (e.second*(e.second - 1) / 2);
	for (auto e : mppa)res -= (e.second*(e.second - 1) / 2);
	cout << res << endl;
	m3lsh;
}
