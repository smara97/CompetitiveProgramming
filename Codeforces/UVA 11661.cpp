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
	while (cin >> n) {
		if (!n)return 0;
		string s;
		cin >> s;
		int ans = 1e7; int p = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'Z') {
				ans = 0;
				break;
			}
			if (s[i] == 'D') {
				for (int j = i; j >= 0; j--) {
					if (s[j] == 'R') {
						ans = min(ans, abs(i - j)); break;
					}
					else if (s[j] == 'D'&&i != j) break;
				}
				for (int j = i; j <s.length(); j++) {
					if (s[j] == 'R') {
						ans = min(ans, abs(i - j)); break;
					}
					else if (s[j] == 'D'&&i != j)break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;

}
