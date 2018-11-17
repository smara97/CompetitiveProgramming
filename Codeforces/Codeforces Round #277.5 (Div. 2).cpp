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
	int n, s;
	cin >> n >> s;
	if (n == 1) {
		if (s <= 9)cout << s << ' ' << s << endl;
		else cout << -1 << ' ' << -1 << endl;
		return 0;
	}
	string resA = "",resB="";
	int sA = s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (i > 0 || j > 0) {
				if ((s - j) >= 0 && (s - j) <= ((n - i - 1) * 9)) {
					resA += char('0' + j), s -= j;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 9; j >=0; j--) {
			if (i > 0 || j > 0) {
				if ((sA - j) >= 0 && (sA - j) <= ((n - i - 1) * 9)) {
					resB += char('0' + j), sA -= j;
					break;
				}
			}
		}
	}

	if (resA.size() == n && resB.size()==n) 
		cout << resA << ' ' << resB << endl;
	else cout << -1 << ' ' << -1 << endl;
	m3lsh;
}
