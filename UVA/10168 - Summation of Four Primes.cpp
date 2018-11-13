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
bitset<20000000>bt;
vector < ll > prim;
void seiev() {
	bt.set();
	bt[0] = bt[1] = 0;
	for (ll i = 2; i <= (1e7) + 5; i++) {
		if (bt[i]) {
			for (ll j = i*i; j <= (1e7) + 5; j += i)bt[j] = 0;
			prim.push_back((ll)i);
		}
	}
}
int main() {
	fast;
	ll n; seiev();
	while (cin >> n) {
		bool ok = 0;
		for (int i = 0; i < prim.size() && !ok; i++) {
			if (prim[i] >= n)break;
			for (int j = 0; j < prim.size() && !ok; j++) {
				if (n < (prim[i] + prim[j]))break;
				for (int k = 0; k < prim.size() && !ok; k++) {
					ll tmp = n;
					if (tmp <= (prim[k] + prim[j] + prim[i]))break;
					tmp -= (prim[k] + prim[j] + prim[i]);
					if (bt[tmp]) {
						ok = 1; 
						cout << prim[i] << ' ' << prim[j] << ' ' << prim[k] << ' ' << tmp << endl;
						break;
					}
				}
			}
		}
		if (!ok)cout << "Impossible." << endl;
	}
	m3lsh;
}
