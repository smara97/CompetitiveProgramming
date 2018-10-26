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
int memo[1001][1001]; string s;
int solve(int i, int j) {
	if (i >= j)return 0;
	int &ret = memo[i][j];
	if (ret != -1)return ret;
	ret = solve(i + 1, j -1) + (s[i] != s[j]);
	ret = min(ret, solve(i + 1, j) + 1);
	ret = min(ret, solve(i, j - 1) + 1);
	return ret;
}
int main()
{
	fast;
	int t; cin >> t;
	int tc = 1;
	while (t--) {
		cin >> s; memset(memo, -1, sizeof memo);
		 cout << "Case "<<tc++<<": "<<solve(0, (int)s.size()-1) << endl;
	}
	m3lsh;
}
