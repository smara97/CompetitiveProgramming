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
	vector<int>v(n),vv;
	for (int i = 0; i < n; i++)cin >> v[i];
	for (int i = 1; i <= n; i++) {
		if (v[i - 1] == i) {
			vv.push_back(v[i - 1]); continue;
		}
			for (int j = i; j < n; j++) {
			if (v[j] == i) {
				for (int k = j; k >= i - 1; k--)
					vv.push_back(v[k]);
				for (int k = j + 1; k < n; k++)
					vv.push_back(v[k]);
				if(is_sorted(vv.begin(),vv.end()))
					cout << i << ' ' << j + 1 << endl;
				else cout << 0 << " " << 0 << endl;
				return 0;
			}
		}
	}
	cout << 0 << ' ' << 0 << endl;
	m3lsh;
}
