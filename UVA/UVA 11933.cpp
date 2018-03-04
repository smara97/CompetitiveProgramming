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
typedef long long ll;
using namespace std;
bool plan(string s) {
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - 1 - i])return 0;
	}
	return 1;
}
int main() {
	ll n;
	while (cin >> n) {
		if (!n)return 0;
		bitset<32>num(n), a, b; bool ok = 0;
		a.reset(); b.reset();
		for (int i = 0; i < num.size(); i++) {
			if (num[i]) {
				if (ok)
					b[i] = 1,ok = 0;
				else a[i] = 1, ok = 1;
			}
		}
		cout << a.to_ullong() << ' ' << b.to_ullong() << "\n";
	}
	return 0;
}
