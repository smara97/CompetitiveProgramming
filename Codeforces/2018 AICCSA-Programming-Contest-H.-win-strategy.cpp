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
int memo[1001][1001], val[1001], len[1001], n,l;
int solve(int ind, int tim) {
	if (ind >= n || tim > l)return 0;
	int &res = memo[ind][tim];
	if (res != -1)return res;
	res = 0;
	res = max(solve(ind + 1, tim), solve(ind, tim + 1));
	if (val[ind] <= tim&&len[ind] + tim <= l+1)res = max(res, 1 + solve(ind + 1, tim + len[ind]));
	return res;
}
int main(){
	fast;
	int t; cin >> t;
	while (t--) {
		cin >> n >> l;
		memset(memo, -1, sizeof memo);
		for (int i = 0; i < n; i++)cin >> val[i] >> len[i];
		cout << solve(0, 0) << endl;
	}
	m3lsh;
}
