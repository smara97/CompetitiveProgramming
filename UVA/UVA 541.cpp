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
		vector<vector<bool>>ad(n, vector<bool>(n));
		pair<int, int>ch; int chr = 0, chc = 0;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				bool x; cin >> x;
				 ad[i][j]=x; sum += ad[i][j];
			}
				
			chr += bool(sum % 2);
			if (sum % 2)ch.first = i + 1;
		}
		for (int i = 0; i< n; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				sum += ad[j][i];
			}
			chc += bool(sum % 2);
			if (sum % 2)ch.second = i + 1;
		}
		if (!chr && !chc)cout << "OK\n";
		else if (chr == 1 && chc == 1) {
			cout << "Change bit (" << ch.first << ',' << ch.second << ")\n";
		}
		else cout << "Corrupt\n";
	}
	return 0;
}
