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
ll solve(ll a, ll b) {
	if (!a || !b)return 0;
	ll ret = 0;
	if (a > b)ret = ret + (solve(a%b, b)) + (a / b);
	else ret = ret + (solve(a, b%a)) + (b / a);
	return ret;
}
int main() {
	fast;
	ll a, b;
	cin >> a >> b;
	cout << solve(a, b) << endl;
	m3lsh;
}
