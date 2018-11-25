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
	int n, k;
	cin >> n >> k;
	vector<int>v(n+1),zer(n+1),one(n+1);
	vector<int>indone;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		if (v[i])indone.push_back(i),v[i]=1;
		else zer[i] = 1;
		zer[i] += zer[i - 1];
		one[i] += one[i - 1];
		if(v[i])mx = max(mx, v[i]);
	}
	int mxop = 0, fi = 0, se = 0;;
	for (int i = 1; i <= n; i++) {
		int b = i, en = n, res = 0, ff = 0, ss = 0;
		while (b <= en) {
			int mid = (b + en) / 2;
			if (zer[mid] - zer[i - 1] <= k) {
				res = max(res, (mid - i + 1));
				ff = i, ss = mid;
				b = mid + 1;
			}
			else en = mid - 1;
		}
		if (mxop < res) {
			mxop=res; fi = ff; se = ss;
		}
	}
	if (mx >= mxop) {
		cout << mx << endl;
		for (int i = 1; i <= n; i++)cout << v[i] << ' ';
		cout << endl;
	}
	else {
		cout << mxop << endl;
		for (int i = fi; i <= se; i++)v[i] = 1;
		for (int i = 1; i <= n; i++)cout << v[i] << ' ';
		cout << endl;
	}
	m3lsh;
}
