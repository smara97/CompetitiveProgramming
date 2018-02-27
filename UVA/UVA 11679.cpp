#define _CRT_SECURE_NO_WARINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<cmath>
#include<bitset>
#include<iterator>
#include<queue>
#include<unordered_map>
#include<iomanip>
#include<functional>
#include<stack>
#include<sstream>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int main() {
	fast;
	int n, m;
	while (cin >> n >> m) {
		if (!n && !m)return 0;
		vector<ll>val(n);
		for (int i = 0; i < n; i++)
			cin >> val[i];
		for (int  i=0; i < m; i++) {
			int l, r, v;
			cin >> l >> r >> v;
			val[l - 1] -= v;
			val[r - 1] += v;
		}
		bool ok = 0;
		for (int i = 0; i < n; i++) {
			ok |= bool(val[i] < 0);
		}
		if (!ok)cout << 'S' << endl;
		else cout << 'N' << endl;
	}
	return 0;

}
