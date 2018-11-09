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
	vector<int>v(n);
	vector<bool>tk(n, 0);
	for (int i = 0; i < n; i++)cin >> v[i];
	sort(v.begin(), v.end());
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (!tk[i]) {
			res++; tk[i] = 0;
			int box = 1, ind = i + 1;
			for (int j = ind; j < n; j++) {
				if (!tk[j] && v[j] >= box) {
					box++; tk[j] = 1;
				}
			}
		}
	}
	cout << res << endl;
	m3lsh;
}
