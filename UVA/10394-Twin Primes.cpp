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
bitset<30000000>bt;
vector<ll>prim; vector<pair<ll, ll>>vp;
void sieve() {
	bt.set();
	bt[0] = bt[1] = 0;
	for (ll i = 2; i <= (ll)2e7; i++) {
		if (bt[i]) {
			for (ll j = i * i; j <= (ll) 2e7; j += i)bt[j] = 0;
			if (i > 2)prim.push_back((ll)i);
		}
	}
	for (int i = 0; i < prim.size() - 1; i++) {
		if (bt[prim[i] + 2])
			vp.push_back({ prim[i], prim[i] + 2 });
	}
}
int main()
{
	fast;
	int n; sieve();
	while (cin >> n){
		cout << "("<<vp[n-1].first<<", "<<vp[n-1].second<<")" << endl;
	}
	m3lsh;
}
