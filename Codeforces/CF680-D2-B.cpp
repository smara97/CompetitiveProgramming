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
	ll n, m;
	cin >> n >> m;
	bitset<100>bt;
	bt.reset();
	for (int i = 0; i < n; i++) {
		bool x;
		cin >> x;
		bt[i] = x;
	}
	ll ans = 0;
	for (int i = m - 1, j = m - 1; i < n || j >= 0; i++,j--) {
		if (j == i&&bt[m - 1] == 1)
			ans++;
		else if (j >= 0 && i < n && bt[j] == 1 && bt[i] == 1)
			ans += 2;
		else if ((j < 0 && bt[i] == 1) || (i >= n  && bt[j] == 1))
			ans++;
	}
	cout << ans << endl;
	return 0;

}
