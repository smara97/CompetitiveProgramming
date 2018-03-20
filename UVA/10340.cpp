#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main() {
	string s, t;
	while (cin >> s >> t) {
		bool ok = 0; int prv = 0,nm = 0;
		for (int i = 0; i < s.length(); i++) {
			for (int j = prv; j < t.length(); j++) {
				if (s[i] == t[j]) {
					prv = j+1; nm++; break;
				}
			}
		}
		if (nm == s.length())cout << "Yes" << endl;
		else cout << "No"<<endl;
	}


	return 0;
}
