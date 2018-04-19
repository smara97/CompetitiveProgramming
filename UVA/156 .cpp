#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
string turn(string s) {
	for (int i = 0; i < s.length(); i++)
		if (s[i] < 97)s[i] = char(s[i] + 32);
	sort(s.begin(), s.end());
	return s;
}
int main()
{
	fast;
	vector<string>vs;
	string s;
	while (cin >> s) {
		if (s == "#")break;
		vs.push_back(s);
	}
	sort(vs.begin(), vs.end());

	for (int i = 0; i < vs.size(); i++) {
		bool ok = 1;
		for (int j = 0; j < vs.size(); j++) {
			if (i != j) {
				if (turn(vs[i]) == turn(vs[j]))ok = 0;
			}
		}
		if (ok)cout << vs[i] << endl;
	}
	return 0;
}
