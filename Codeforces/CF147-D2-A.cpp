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
	string s, ans = "";
	getline(cin, s);
	for (int i = 0; i < s.length()-1; i++) {
		if (s[i] == ' ') {
			if (!isalpha(s[i + 1])) {
				if (s[i + 1] != ' ')
					swap(s[i], s[i + 1]);
				else s.erase(i, 1); i--;
			}
		}
	}
	for (int i = 0; i < s.length() - 1; i++) {
		ans += s[i];
		if (!isalpha(s[i])) {
			if (s[i] != ' ') {
				if (s[i + 1] != ' ')ans += ' ';
			}
		}
	}
	ans += s.back();
	cout << ans << endl;
	return 0;

}
