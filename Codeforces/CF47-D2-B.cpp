#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
int main()
{
	fast;
	int ch[3] = { 0 };
	string ss = "ABC";
	for (int i = 0; i < 3; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (isalpha(s[j])) {
				if (j) {
					if (s[j - 1] == '>')ch[s[j]-'A']--;
					else ch[s[j] - 'A']++;
				}
				else {
					if (s[j + 1] == '>')ch[s[j] - 'A']++;
					else ch[s[j] - 'A']--;
				}
			}
		}
	}
	int ne = 0, po = 0, ze = 0;
	for (int i = 0; i < 3; i++) {
		ne += bool(ch[i] < 0);
		po += bool(ch[i] > 0);
		ze += bool(ch[i] == 0);
	}
	if (ze == 1 && po == 1 && ne == 1) {
		for (int i = 0; i < 3; i++)
			if (ch[ss[i] - 'A'] == -2)cout << ss[i];
		for (int i = 0; i < 3; i++)
			if (ch[ss[i] - 'A'] == 0)cout << ss[i];
		for (int i = 0; i < 3; i++)
			if (ch[ss[i] - 'A'] == 2)cout << ss[i];
		cout << endl;
	}
	else cout << "impossible" << endl;
	return 0;
}

