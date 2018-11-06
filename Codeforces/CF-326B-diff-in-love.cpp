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
vector<int>fi;
bool valid(queue<int>q) {
	if (q.size() != fi.size())return  0;
	int ret = 0;
	for (int i = 0; i < fi.size(); i++) {
		ret += (fi[i] == q.front());
		q.pop();
	}
	return (ret == fi.size());
}
int main() {
	fast;
	ll n; cin >> n;
	vector<ll>dv;
	for (ll i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			dv.push_back(i);
			if (i != n / i)dv.push_back(n / i);
		}
	}
	dv.push_back(n);
	sort(dv.begin(), dv.end());
	ll res = n;
	for (ll i = dv.size() - 1; i >= 0; i--) {
		ll nm = dv[i]; bool ok = 1;
		for (int j = 0; j < dv.size(); j++) {
			if (dv[j] * dv[j] > nm)break;
			if (nm%dv[j] == 0) {
				if (nm % (dv[j] * dv[j])==0) {
					ok = 0; break;
				}
			}
		}
		if (ok) {
			res = dv[i]; break;
		}
	}
	cout << res << endl;   //complexity log(n*log(log(n)));
	m3lsh;
}
