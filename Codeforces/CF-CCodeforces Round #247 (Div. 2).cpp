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
int memo[300][3];
int n, k, d;
ll mod = (ll)1e9 + 7;
ll solve(int len, bool ok) {
	if (len == n)
		return ok;
	if (len > n)return 0;
	int &ret = memo[len][ok];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = 1; i<= k; i++) {
		if (i >= d)
			ret = (ret + solve(len + i, 1)) % mod;
		else ret = (ret + solve(len + i, ok)) % mod;
	}
	return ret;
}
int main() {
	fast;
	cin >> n >> k >> d;
	memset(memo,-1, sizeof memo);
	cout << solve(0, 0) << endl;
	m3lsh;
}
