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
int main()
{
	fast;
	ll a, b; cin >> a >> b;
	int po = 0, res = 0;
	while (a % 2 == 0)a /= 2, po++;
	while (b % 2 == 0)b /= 2, po--;
	res += abs(po); po = 0;
	while (a % 3 == 0)po++, a /= 3;
	while (b % 3 == 0)po--, b /= 3;
	res += abs(po), po = 0;
	while (a % 5 == 0)po++, a /= 5;
	while (b % 5 == 0)b /= 5, po--;
	res += abs(po);
	if (a == b)cout << res << endl;
	else cout << -1 << endl;
	m3lsh;
}
