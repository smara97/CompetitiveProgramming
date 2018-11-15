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
ll one[100001], zer[100001];
int main() {
	fast;
	int n, q;
	cin >> n >> q;
	string s; cin >> s;
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '.'&&s[i + 1] == '.')res++;
	}
	while (q--) {
		int x; char y;
		cin >> x >> y;
		if (y != '.') {
			x--;
			if (!x) {
				if (s[x] == '.' && s[x + 1] == '.')res--;
			}
			else {
				if (s[x] == '.' && s[x - 1] == '.')res--;
				if (s[x] == '.' && s[x + 1] == '.')res--;
			}
			s[x] = y;
		}
		else {
			x--;
			if (s[x] != '.') {
				s[x] = '.';
				if (!x) {
					if (s[x] == '.'&&s[x + 1] == '.')res++;
				}
				else {
					if (s[x] == '.'&&s[x + 1] == '.')res++;
					if (s[x] == '.'&&s[x - 1] == '.')res++;
				}
			}
		}
		cout << res << endl;
	}

	m3lsh;
}
