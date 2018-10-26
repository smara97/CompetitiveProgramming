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
ll memo[1001][1001], cut[1001];
ll solve(int st, int en, int inds, int inde) {
	if (st == en || inds > inde)return 0;
	ll &ret = memo[inds][inde];
	if (ret != -1)return ret;
	ret = 1e9;
	for (int i = inds; i <= inde; i++)
		ret = min(ret, solve(st, cut[i], inds, i-1) + solve(cut[i]+1, en, i+1, inde) + (en - st+1));
	return ret;
}
int main()
{
	fast;
	int l; 
	while (cin >> l) {
		if (!l)break;
		int n; cin >> n;
		memset(memo, -1, sizeof memo);
		for (int i = 1; i <= n; i++)cin >> cut[i];
		cout << "The minimum cutting is "<<solve(1, l, 1, n)<<"." << endl;
	}
	m3lsh;
}
