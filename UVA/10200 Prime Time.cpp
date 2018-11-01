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
int prim[100001] = { 0 };
void iset() {
	for (ll i = 0; i <= 10000; i++) {
		ll num = (i*i + i + 41); bool ok = 1;
		prim[i + 1] = prim[i];
		for (ll j = 2; j*j <= num; j++) {
			if (num%j == 0) {
				ok = 0; break;
			}
		}
		if (ok)prim[i + 1]++;
	}
}
int main(){
	fast;
	ll a, b;
	memset(prim, 0, sizeof prim);
	iset();
	while (cin>>a>>b) {
		double ans = double(prim[b + 1] - prim[a]) / double(b - a + 1);
		cout << fixed << setprecision(2) << ans*100.00 + 1e-6 << endl;
	}
	m3lsh;
}
