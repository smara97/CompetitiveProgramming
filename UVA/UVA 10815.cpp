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
	string s;
	while (getline(cin, s)) {
		if (s == "DONE")return 0;
		for (int i = 0; i < s.length(); i++) {
			if (isalpha(s[i])) {
				s[i] = s[i] + (bool(s[i] < 97) * 32);
			}
			else s.erase(i, 1), i--;
		}
		if (plan(s))cout << "You won't be eaten!\n";
		else cout << "Uh oh..\n";
	}
	return 0;
}
