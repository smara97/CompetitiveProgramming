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
	ll n, k; cin >> n >> k;
	vector<ll>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	sort(v.begin(), v.end());
	int nod = v[0],res=0;
	map<ll, ll>mp;
	for (int i = 0; i < n; i++) {
		if (mp[v[i]/k] && v[i]%k==0)continue;
		mp[v[i]]++; res++;
	}
	cout << res << endl;
	m3lsh;
}
