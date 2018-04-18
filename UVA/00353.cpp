#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
int main()
{
	fast;
	string s;
	while (cin >> s) {
		int res = 0;
		map<string, bool>mp;
		for (int i = 0; i < s.length(); i++) {
			for (int j = 1; j <= (s.length() - i); j++) {
				string ss = s.substr(i, j);
				string srv = ss;
				reverse(ss.begin(), ss.end());
				if(!mp[ss])
					res += bool(srv == ss),mp[ss]=1;
			}
		}
		cout << "The string '" << s << "' contains " << res << " palindromes." << endl;
	}
	return 0;
}
