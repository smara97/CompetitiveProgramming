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
int n, we[1001], va[1001];
int memo[1001][1001];
int solve(int rem, int ind) {
	if (ind == n)return 0;
	if (memo[ind][rem] != -1)return memo[ind][rem];
	int &ans = memo[ind][rem];
	if (rem >= we[ind]) {
		ans = max(ans, max(solve(rem - we[ind], ind + 1) + va[ind], solve(rem, ind + 1)));
	}
	else ans = max(ans, solve(rem, ind + 1));
	return ans;
}
int main()
{
	fast;
	int t; cin >> t;
	while (t--) {
		memset(memo, -1, sizeof memo);
		cin >> n;
		for (int i = 0; i < n; i++)cin >> va[i] >> we[i];
		int x; cin >> x;
		ll res = 0;
		while (x--) {
			int xx; cin >> xx;
			res += solve(xx, 0);
		}
		cout << res << endl;
	}
	m3lsh;
}
