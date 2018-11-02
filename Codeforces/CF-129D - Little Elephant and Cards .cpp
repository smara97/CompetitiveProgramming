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
ll fi[100001], se[100001];
map<ll, int>mpf, mps;
map<pair<ll, ll>,int>pa;
int main(){
	fast;
	int n; cin >> n;
	int haf = (int)ceil(n / 2.0);
	for (int i = 0; i < n; i++) {
		cin >> fi[i] >> se[i];
		mpf[fi[i]]++; mps[se[i]]++;
		pa[{fi[i], se[i]}]++;
	}
	ll res = INT_MAX;
	for (auto e : mpf) {
		if (e.second >= haf)res = 0;
		else {
			if (mps[e.first] - pa[{e.first,e.first}] >= (haf - e.second))
				res = min(res, (ll)(haf - e.second));
		}
	}
	for (auto e : mps) {
		if (e.second >= haf)res = min(res, (ll)haf);
		else {
			if (mpf[e.first] - pa[{e.first, e.first}] >= (haf - e.second))
				res = min(res, (ll)(haf - e.second+e.second));
		}
	}
	if (res == INT_MAX)res = -1;
	cout << res << endl;
	m3lsh;
}
