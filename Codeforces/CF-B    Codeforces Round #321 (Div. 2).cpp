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

int main() {
	fast;
	ll n, d;
	cin >> n >> d;
	vector<pair<ll,ll>>cost(n);
	for (int i = 0; i < n; i++) {
		cin >> cost[i].first >> cost[i].second;
	}
	sort(cost.begin(), cost.end());
	for (int i = 1; i < n; i++) {
		cost[i].second += cost[i - 1].second;
	}
	vector<ll>op;
	for (int i = 0; i < n; i++)op.push_back(cost[i].first);
	ll res = 0;
	for (int i = 0; i < n; i++) {
		int lo = lower_bound(op.begin(), op.end(), cost[i].first + d) - op.begin()-1;
		if(!i)res = max(res, (cost[lo].second));
		else res = max(res, (cost[lo].second - cost[i - 1].second));
	}
	cout << res << endl;
	m3lsh;
}
