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
	ll n;
	cin >> n;
	vector<ll>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.rbegin(), v.rend());
	ll num1 = 0, cnt = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] % 2) {
			if (cnt == 1)ans += (num1 + v[i]), cnt = 0;
			else cnt++,num1=v[i];
		}
		else ans += v[i];
	}
	cout << ans << endl;
	return 0;

}
