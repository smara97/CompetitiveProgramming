#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
int mx(string s) {
	int ret =0 ;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; (j+i)<= s.length(); j++) {
			string tmp = "";
			for (int k = i; k < (j + i); k++)tmp += s[k];
			if (tmp.length() % 2 == 0) {
				bool ok = 1;
				for (int k = 0; k < (tmp.length() / 2); k++) {
					if (tmp[k] == '.' || tmp[(tmp.length() / 2 + k)] == '.')continue;
					else if (tmp[k] != tmp[tmp.length() / 2 + k]) {
						ok = 0; break;
					}
				}
				if (ok)ret = max((int)tmp.length(), ret);
			}
		}
	}
	return ret;
}
int main()
{
	fast;
	string s;
	cin >> s;
	int k; cin >> k;
	string tmp = "";
	for (int i = 0; i < k; i++)tmp += '.';
	s += tmp;
	cout << mx(s) << endl;
	return 0;
} 
