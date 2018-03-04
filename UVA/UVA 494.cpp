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
	string s; vector<string>vs;
	while(getline(cin,s)){
		ll ans = 0;
		for (int i = 0; i < s.length(); i++) {
			if (isalpha(s[i])) {
				ans++;
				while (i < s.length() && isalpha(s[i])) i++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
