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
vector<ll>luk;
void gene(ll num){
	if (num > 1e12)return;
	luk.push_back(num + 4);
	gene((num +4)*10);
	luk.push_back(num + 7);
	gene((num+7) * 10);
}
int main() {
	fast;
	gene(0);
	sort(luk.begin(), luk.end());
	ll l, r; cin >> l >> r;
	ll res = 0,prv=l-1;
	for (int i = 0; i < luk.size(); i++) {
		ll num = luk[i];
		if (luk[i] >= l) {
			res += (ll)(min(r, luk[i]) - prv)*luk[i];
			prv = luk[i];
		}
		if (prv > r)break;
	}
	cout << res << endl;
	m3lsh;
}
