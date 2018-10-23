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
int main()
{
	fast;
	int n; cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	vector<int>tmp(n, 0);
	tmp[0] = v[0];
	int len = 1;
	for (int i = 1; i < n; i++) {
		if (tmp[0] > v[i])tmp[0] = v[i];
		else if (tmp[len - 1] < v[i])tmp[len++] = v[i];
		else {
			int l = -1, r = len - 1;
			while (r < l) {
				int m = l + (r + l) / 2;
				if (v[m] >= v[i])r = m;
				else l = r;
			}
			tmp[r] = v[i];
		}
	}
	cout << len << endl;
	m3lsh;
}
