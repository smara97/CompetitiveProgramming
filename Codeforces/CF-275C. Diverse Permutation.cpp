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
	int n, k,tmp;
	cin >> n >> k;
	vector<bool>vis(n + 1, 0);
	int mins = 1, prv = n;
	vector<int>res; tmp = k;
	res.push_back(n); vis[n] = 1;
	while (k) {
		if (mins)prv -= k;
		else prv += k;
		vis[prv] = 1;
		k--; mins = 1-mins;
		res.push_back(prv);
	}
	vector<int>pu;
	for (int i = 1; i < n; i++) {
		if (!vis[i])pu.push_back(i);
	}
	sort(pu.begin(), pu.end());
	if (pu.size()) {
		if (abs(pu.back() - res.back()) <= k)
			for (int i = 0; i < pu.size(); i++)res.push_back(pu[i]);
		else
			for (int i = pu.size() - 1; i >= 0; i--)res.push_back(pu[i]);
	}
	for (int i = 0; i < res.size(); i++)cout << res[i] << ' '; cout << endl;
	m3lsh;
}
