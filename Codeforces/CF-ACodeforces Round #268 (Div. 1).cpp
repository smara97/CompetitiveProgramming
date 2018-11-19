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
	ll n; cin >> n;
	if (n < 4 )cout << "NO" << endl;
	else if (n == 4) {
		cout << "YES" << endl;
		int mul = 1;
		for (int i = 2; i <=4; i++) {
			cout << mul << " * " << i << " = " << mul*i << endl;
			mul *= i;
		}
	}
	else {
		int mul = 1; cout << "YES" << endl;
		if (n % 2 == 0) {
			for (int i = 2; i <= 4; i++) {
				cout << mul << " * " << i << " = " << mul*i << endl;
				mul *= i;
			}
			for (int i = 5; i < n; i += 2) {
				cout << i + 1 << " - " << i << " = " << 1 << endl;
				cout << mul << " * " << 1 << " = " << mul << endl;
			}
		}
		else {
			cout << "5 - 3 = 2"<<endl;
			cout << "2 * 4 = 8" << endl;
			cout << "1 + 2 = 3" << endl;
			cout << "8 * 3 = 24" << endl;
			mul = 24;
			for (int i = 6; i < n; i += 2) {
				cout << i + 1 << " - " << i << " = " << 1 << endl;
				cout << mul << " * " << 1 << " = " << mul << endl;
			}
		}
	}
	m3lsh;
}
