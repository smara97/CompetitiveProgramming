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
ll grid[101][101];
ll solve(int s) {
	ll ret = 0;
	for (int i = 1; i <= s; i++) {
		int kad[101] = { 0 };
		for (int j = i; j <= s; j++) {
			for (int k = 1; k <= s; k++)kad[k] += grid[k][j];
			ll sum = 0,mx=0;
			for (int k = 1; k <= s; k++) {
				sum += kad[k];
				if (sum < 0)sum = 0;
				mx = max(mx, sum);
			}
			ret = max(ret, mx);
		}

	}
	return ret;
}
void mem(int s) {
	for (int i = 0; i <= s; i++)
		for (int j = 0; j <= s; j++)
			grid[i][j] = 1;
}
int main()
{
	fast;
	int tc; cin >> tc;
	while (tc--) {
		int s,b; cin >> s;
		cin >> b; mem(s);
		while (b--) {
			int lr, rr, lc, rc;
			cin >> lr >> lc >> rr >> rc;
			if (lr > rr)swap(lr, rr);
			if (lc > rc)swap(rc, lc);
			for (int i = lc; i <= rc;i++) {
				for (int j = lr; j <= rr; j++) {
					grid[i][j] = -1e5;
				}
			}
		}
		cout << solve(s) << endl;
	}
	m3lsh;
}
