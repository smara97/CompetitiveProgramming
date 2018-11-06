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
bitset<10000000>bt;
void seive(ll num) {
	bt.set();
	bt[0] = bt[1] = 0;
	for (ll i = 2; i <= num; i++) {
		if (bt[i])
			for (ll j = i*i; j <= num; j+=i)bt[j] = 0;
	}
}
int main() {
	fast;
	int n; cin >> n;
	vector<ll>v(n);
	seive(2*(ll)1e6);
	bool exis = 0; int ind = -1;
	for (int i = 0; i < n; i++) cin >> v[i], exis |= bool(v[i] == 1);
	int mxres = 0;
	vector<int>fitone,paprime;
	sort(v.begin(), v.end());
	if (exis) {
		for (int i = 0; i < n; i++) {
			if (bt[v[i] + 1]) {
				fitone.push_back(v[i]);
				if (v[i] != 1)break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (bt[(v[i] + v[j])]) {
				paprime.push_back(v[i]);
				paprime.push_back(v[j]);
				break;
			}
		}
		if (paprime.size())break;
	}
	int mx = max((int)1, (int)max(paprime.size(), fitone.size()));
	cout << mx << endl;
	if (mx == paprime.size())
		for (int i = 0; i < mx; i++)cout << paprime[i] << ' ';
	else if (fitone.size() == mx)
		for (int i = 0; i < mx; i++)cout << fitone[i] << ' ';
	else cout << v[0];
	cout << endl;
	m3lsh;
}
