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
	int n, q;
	cin >> n >> q;
	vector<ll>v(n),vv(n+3);
	vector<ll>ind((int)1e6 + 1,0);
	for (int i = 0; i < n; i++)cin >> v[i];
	vector<pair<ll, ll>>qv(q);
	for (int i = 0; i < q; i++) {
		cin >> qv[i].first >> qv[i].second;
		ind[qv[i].first]++;
		ind[qv[i].second + 1]--;
	}
	for (int i = 1; i <= n + 1; i++)ind[i] += ind[i - 1];
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	for (int i = 1; i <= n; i++) {
		pq.push({ -ind[i],i });
	}
	sort(v.begin(), v.end());
	while (pq.size()) {
		int ocu = -pq.top().first;
		vv[pq.top().second] = v.back();
		v.pop_back(); pq.pop();
	}
	for (int i = 1; i <= n; i++)vv[i] += vv[i - 1];
	ll res = 0;	
	for (int i = 0; i < q; i++) {
		res += (vv[qv[i].second] - vv[qv[i].first-1]);
	}
	cout << res << endl;
	m3lsh;
}
