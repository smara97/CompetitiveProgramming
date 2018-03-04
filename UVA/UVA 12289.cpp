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
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		if (s.size() < 5) {
			int on = 0, to = 0; string t = "two", o = "one";
			for (int i = 0; i < s.length(); i++) {
				to += bool(s[i] != t[i]);
				on += bool(s[i] != o[i]);
			}
			if (on < to)cout << 1 << "\n";
			else cout << 2 << "\n";
		}
		else cout << 3 << "\n";
	}
	return 0;
}
