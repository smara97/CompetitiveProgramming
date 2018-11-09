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
	vector<int>v(n);	
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		pq.push({ 10 - (x % 10) ,x});
	}
	while (pq.size()) {
		int m7tg = pq.top().first, prv = pq.top().second;
		pq.pop();
		if (k >= m7tg && (m7tg+prv)<=100) {
			if ((prv + m7tg) <= 100) {
				prv += m7tg;
				pq.push({ 10,prv });
				k -= m7tg;
			}
		}
		else res+=(prv/10);
	}
	cout << res << endl;
	m3lsh;
}
