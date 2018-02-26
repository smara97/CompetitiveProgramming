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
	int n;
	cin >> n;
	cin.ignore();
	string s;
	cin >> s;
	set<char>se;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] < 97) {
			s[i] = char(s[i] + 32);
		}
		se.insert(s[i]);
	}
	if (se.size()==26) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	return 0;

}
