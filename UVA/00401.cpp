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
	map<char, char>mp;
	map<char, bool>mpt;
	mp['A'] = 'A'; mpt['A'] = 1; mp['V'] = 'V'; mpt['V'] = 1;
	mp['E'] = '3'; mpt['E'] = 1; mp['W'] = 'W'; mpt['W'] = 1;
	mp['H'] = 'H'; mpt['H'] = 1; mp['X'] = 'X'; mpt['X'] = 1;
	mp['I'] = 'I'; mpt['I'] = 1; mp['Y'] = 'Y'; mpt['Y'] = 1;
	mp['L'] = 'J'; mpt['L'] = 1; mp['Z'] = '5'; mpt['Z'] = 1;
	mp['J'] = 'L'; mpt['J'] = 1; mp['1'] = '1'; mpt['1'] = 1;
	mp['M'] = 'M'; mpt['M'] = 1; mp['2'] = 'S'; mpt['2'] = 1;
	mp['O'] = 'O'; mpt['O'] = 1; mp['3'] = 'E'; mpt['3'] = 1;
	mp['S'] = '2'; mpt['S'] = 1;mp['5'] = 'Z'; mpt['5'] = 1;
	mp['T'] = 'T'; mpt['T'] = 1;mp['8'] = '8'; mpt['8'] = 1;
	mp['U'] = 'U'; mpt['U'] = 1;
	while (cin >> s) {
		bool plan = 1, mir = 1;
		for (int i = 0; i < s.length() / 2; i++) {
			plan &= bool(s[i] == s[s.length() - i - 1]);
		}
		if (s.length() % 2==1)mir &= bool(mpt[s[s.length() / 2]]);
		for (int i = 0; i < s.length() / 2; i++) {
			if (mpt[s[s.length() - i - 1]]) {
				mir &= bool(mp[s[s.length() - i - 1]] == s[i]);
			}
			else mir = 0;
		}
		if (mir&&plan)cout << s<<" -- is a mirrored palindrome." << endl;
		else if (mir&&!plan)cout << s << " -- is a mirrored string." << endl;
		else if (!mir&&plan)cout << s << " -- is a regular palindrome." << endl;
		else cout << s << " -- is not a palindrome." << endl;
		cout << endl;
	}
	return 0;
}
