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
	ll n, q,cn=0;
	cin >> n >> q;
	vector<ll>v(n),pre(n); vector<bool>vi(1e5 + 1,0);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = n - 1; i >= 0; i--) {
		if (!vi[v[i]]) {
			cn++;
			vi[v[i]] = 1;
		}
		pre[i] = cn;
	}
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		cout << pre[x - 1] << endl;
	}
	return 0;

}
