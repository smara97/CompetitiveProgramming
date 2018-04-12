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
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	map<char, int>mp;
	for (int i = 0; i < s1.length(); i++)if(isalpha(s1[i])) mp[s1[i]]++;
	for (int j = 0; j < s2.length(); j++) {
		if (isalpha(s2[j])) {
			if (!mp[s2[j]]) {
				cout << "NO" << endl;
				return 0;
			}
			mp[s2[j]]--;
		}
	}
	cout << "YES" << endl;
	return 0;
}
