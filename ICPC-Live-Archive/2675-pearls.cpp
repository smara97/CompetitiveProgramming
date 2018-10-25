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
ll n, cls[1001], val[1001], memo[1001][1001];
ll solve(int curind, int lasind, ll sum=0) {
	if (curind == n) {
		if (curind != lasind)return (ll)1e9;
		return 0;
	}
	if (memo[curind][lasind] != -1)return memo[curind][lasind];
	ll &ret = memo[curind][lasind];
	ret = solve(curind + 1, curind + 1, 0) + ((sum + 10+cls[curind])*val[curind]);
	ret = min(ret,solve(curind+1,lasind,sum+cls[curind]));
	return ret;
}
int main()
{
	fast;
	int t; cin >> t;
	while (t--) {
		cin >> n; memset(memo, -1, sizeof memo);
		for (int i = 0; i < n; i++)cin >> cls[i] >> val[i];
		cout << solve(0, 0, 0) << endl;
	}
	m3lsh;
}
