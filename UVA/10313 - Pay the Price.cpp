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
int n;
ll memo[400][400][400];
ll solve(int rem, int ind, int cur) {
	if (!cur && !rem)return 1;
	if (rem<0 || !cur || ind>300)return 0;
	ll &ret = memo[rem][ind][cur];
	if (ret != -1)return ret;
	ret = 0;
	ret = solve(rem - ind, ind, cur - 1) + solve(rem, ind + 1, cur);
	return ret;
}
int main()
{
	fast;
	string s; 
	memset(memo, -1, sizeof memo);
	while (getline(cin,s)) {
		istringstream iss(s); int x;
		vector<int>v;
		while (iss >> x)
			v.push_back(x);
		int st = 0, en = 0; n = 0;
		if (v.size() == 1)st = 0, en = v[0], n = v[0];
		else if (v.size() == 2)st = 0, en = v[1], n = v[0];
		else n = v[0], st = v[1], en = v[2];
		ll ret = 0;
		en = min(en, n);
		for (int i = st; i <= en; i++)ret += solve(n, 1, i);
		cout << ret << endl;
	}
	m3lsh;
}
