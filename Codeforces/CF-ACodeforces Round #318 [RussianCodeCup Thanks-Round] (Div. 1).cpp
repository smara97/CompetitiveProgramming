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
	int n; cin >> n;
	vector<ll>v(n);
	set<int>st;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		while (v[i] % 2 == 0)v[i] /= 2;
		while (v[i] % 3 == 0)v[i] /= 3;
		st.insert(v[i]);
	}
	if (st.size() == 1)cout << "Yes" << endl;
	else cout << "No" << endl;
	m3lsh;
}
