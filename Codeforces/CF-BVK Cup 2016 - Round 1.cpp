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
	int n, d, h;
	cin >> n >> d >> h;
	vector < pair<int, int>>res;
	if (d == 1 && h == 1) {
		if (n == 2)cout << 1 << ' ' << 2 << endl;
		else cout << -1 << endl;
		return 0;
	}
	bool ok = 1; int curnode = 2,cnt=h;
	for (int i = 2; i <= n; i++) {
		res.push_back({ i - 1,i }); h--;
		if (!h)break; curnode = i + 1;
	}
	if (h) { cout << 0 - 1 << endl; return 0; }
	d -= cnt; curnode++;
	if (d < 0) { cout << -1 << endl; return 0; }
	if (!d) {
			for (curnode; curnode <= n; curnode++)res.push_back({ 2,curnode });
			for (auto p : res)cout << p.first << ' ' << p.second << endl;
			return 0;
	}
	res.push_back({ 1,curnode }); curnode++; d--; cnt--;
	for ( curnode; curnode <= n; curnode++) {
		if (!d)break; d--; cnt--;
		res.push_back({ curnode,curnode-1 });
	}
	if (cnt < 0) { cout << -1 << endl; return 0; }
	for (curnode; curnode <= n; curnode++)res.push_back({ 1,curnode });
	for (auto p : res)cout << p.first << ' ' << p.second << endl;
	m3lsh;
}
