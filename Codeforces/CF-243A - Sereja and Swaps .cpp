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

int main(){
	fast;
	int n, k;
	cin >> n >> k;
	vector<ll>v(n),vso(n);
	for (int i = 0; i < n; i++)cin >> v[i], vso[i] = v[i];
	sort(vso.rbegin(), vso.rend());
	ll res = INT_MIN;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			vector<ll>fi, se; int tmp = k;
			for (int kk = 0; kk < n; kk++) {
				if (kk >= i && kk <= j)fi.push_back(v[kk]);
				else se.push_back(v[kk]);
			}
			sort(fi.begin(), fi.end());
			sort(se.rbegin(), se.rend());
			for (int kk = 0; kk < min(fi.size(), se.size()); kk++) {
				if (fi[kk] < se[kk])
					if (tmp)swap(fi[kk], se[kk]), tmp--;
			}
			ll sum = 0;
			for (int kk = 0; kk < fi.size(); kk++)sum += fi[kk];
			res = max(res, sum);
		}
	}
	cout << res << endl;
	m3lsh;
}
