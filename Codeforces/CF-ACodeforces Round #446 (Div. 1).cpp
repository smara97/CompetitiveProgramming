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
ll SP[2222][100];
int main() {
	fast; 
	int n; cin >> n;
	vector<ll>v(n);
	int one = 00,gc;
	for (int i = 0; i < n; i++) {
		cin >> v[i]; one += bool(v[i] == 1);
	}
	gc = v[0];
	for (int i = 1; i < n; i++)gc = gcd(v[i], gc);
	if (one) {
		cout << n - one << endl; return 0;
	}
	int lgk = log2(n);
	for (int i = 0; i < n; i++)SP[i][0] = v[i];
	for (int j = 1; j <= lgk; j++) {
		for (int i = 0; (i + (1 << j) - 1) < n; i++) {
			SP[i][j] = gcd(SP[i][j - 1], SP[i + (1 << (j - 1))][j - 1]);
		}
	}
	int res = 1e8;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int k = log2(j - i + 1);
			if ((gcd(SP[i][k], SP[j - (1 << k) + 1][k])) == 1)
				res = min(res, n - 1 + j - i);
		}
	}
	if (res == 1e8)res = -1;
	cout << res << endl;
	m3lsh;
}
