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
	int sum, lim;
	cin >> sum >> lim;
	ll res = 0; vector<pair<int,int>>v;
	for (int i = 1; i <= lim; i++) {
		v.push_back({ i&(-i),i });
	}
	sort(v.rbegin(), v.rend());
	int ii = 0; vector<int>pu;
	for (int i = 0; i < v.size(); i++,ii++) {
		res += v[i].first;
		if (res > sum)res -= v[i].first;
		else pu.push_back(v[i].second);
	}
	if (res == sum) {
		cout << pu.size() << endl;
		for (int i = 0; i <pu.size(); i++)
			cout << pu[i] << ' '; cout << endl;
	}
	else cout << -1 << endl;
	m3lsh;
}
