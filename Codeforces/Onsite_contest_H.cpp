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
	vector<ll>com(n+1,0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int q;
	cin >> q;
	vector<ll>pu;
	while (q--) {
		int l, r;
		cin >> l >> r;
		com[l - 1] += 1;
		com[r] -= 1;
	}
	for (int i = 1; i < n; i++) {
		com[i] += com[i - 1];
	}
	for (int i = 0; i < n; i++)
		if (!com[i])
			pu.push_back(v[i]);
	cout << pu.size() << endl;
	for (int i = 0; i < pu.size(); i++)
		cout << pu[i] << ' ';
	cout << endl;
	return 0;

}
