#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main()
{
	fast;
	map<string, int>mp;
	int prv = 1;
	for (char a = 'a'; a <= 'z'; a++) {
		string s = ""; s += a;
		mp[s] = prv++;
	}
	for (char a = 'a'; a <= 'z'; a++) {
		for (char b = char(a + 1); b <= 'z'; b++) {
			string s = ""; s += a; s += b;
			mp[s]=prv++;
		}
	}
	for (char a = 'a'; a <= 'z'; a++) {
		for (char b = char(a + 1); b <= 'z'; b++) {
			for (char c = char(b + 1); c <= 'z'; c++) {
				string s = ""; s += a; s += b; s += c;
				mp[s]=prv++;
			}
		}
	}
	for (char a = 'a'; a <= 'z'; a++) {
		for (char b = char(a + 1); b <= 'z'; b++) {
			for (char c = char(b + 1); c <= 'z'; c++) {
				for (char d = char(c + 1); d<= 'z'; d++) {
					string s = ""; s += a; s += b; s += c;
					s += d;
					mp[s] = prv++;
				}
			}
		}
	}
	for (char a = 'a'; a <= 'z'; a++) {
		for (char b = char(a + 1); b <= 'z'; b++) {
			for (char c = char(b + 1); c <= 'z'; c++) {
				for (char d = char(c + 1); d <= 'z'; d++) {
					for (char e = char(d + 1); e <= 'z'; e++) {

						string s = ""; s += a; s += b; s += c;
						s += d; s += e;
						mp[s] = prv++;
					}
				}
			}
		}
	}
	string ss;
	while (cin >> ss) {
		cout << mp[ss] << endl;
	}
	return 0;
}
