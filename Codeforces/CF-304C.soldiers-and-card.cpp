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
vector<int>fi;
bool valid(queue<int>q) {
	if (q.size() != fi.size())return  0;
	int ret = 0;
	for (int i = 0; i < fi.size(); i++) {
		ret += (fi[i] == q.front());
		q.pop();
	}
	return (ret == fi.size());
}
int main() {
	fast;
	int n; cin >> n;
	int x; cin >> x;
	ll fun = 1;
	for (int i = 1; i <= n+1; i++)fun *= i;
	queue<int>q, qq,pro;
	for (int i = 0; i < x; i++) {
		int y; cin >> y; fi.push_back(y);
		q.push(y); pro.push(y);
	}
	cin >> x;
	for (int i = 0; i < x; i++) {
		int y; cin >> y;
		qq.push(y);
	}
	ll ret = 0; bool ok = 1;
	while (q.size() && qq.size() && ok) {
		int qv = q.front(); q.pop();
		int qqv = qq.front(); qq.pop();
		if (qv > qqv) {
			q.push(qqv); q.push(qv);
		}
		else {
			qq.push(qv);qq.push(qqv);
		}
		ret++; if (ret > fun)ok = 0;
	}
	if (ok) {
		cout << ret << ' ';
		if (q.size())cout << 1 << endl;
		else cout << 2 << endl;
	}
	else cout << -1 << endl;
	m3lsh;
}
