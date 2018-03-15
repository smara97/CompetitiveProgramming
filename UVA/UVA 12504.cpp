#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main() {
	fast;
	int tc;
	cin >> tc;
	cin.ignore();
	tc *= 2;
	map<string, string>mp, mpn; map<string, int> mpt;
	for (int t = 1; t <= tc; t++) {
		string s; getline(cin, s);
		for (int i = 1; i < s.length(); i++) {
			if (isalpha(s[i])) {
				string temp = "", tempv = ""; int j = i;
				while (isalpha(s[j]))temp += s[j], j++;
				j++;
				while (s[j] != ','&&s[j] != '}')tempv += s[j], j++;
				if(t%2==1)mp[temp] = tempv;
				else mpn[temp] = tempv;
				mpt[temp]++;
				i = j;
			}
		}
		if (t % 2 == 0) {
			set<string>inc, dec, ch;
			map<string, string>::iterator it = mp.begin(), itn = mpn.begin();
			while (it != mp.end()) {
				if (mpt[it->first] == 2) {
					if (mp[it->first] != mpn[it->first])ch.insert(it->first);
				}
				else dec.insert(it->first);
				it++;
			}
			while (itn != mpn.end()) {
				if (mpt[itn->first] == 2) {
					if (mp[itn->first] != mpn[itn->first])ch.insert(itn->first);
				}
				else inc.insert(itn->first);
				itn++;
			}
			if (!inc.empty() || !dec.empty() || !ch.empty()) {
				if (inc.size()) {
					cout << '+';
					set<string>::iterator in = inc.begin(), ine = inc.end(); ine--;
					while (in != inc.end()) {
						if (in == ine)cout << *in << endl;
						else cout << *in << ',';
						in++;
					}
				}
					if (dec.size()) {
						cout << '-';
						set<string>::iterator dc = dec.begin(), dce = dec.end(); dce--;
						while (dc != dec.end()) {
							if (dc == dce)cout << *dc << endl;
							else cout << *dc << ',';
							dc++;
						}
					}
					if (ch.size()) {
						cout << '*';
						set<string>::iterator c = ch.begin(), ce = ch.end(); ce--;
						while (c != ch.end()) {
							if (c == ce)cout << *c << endl;
							else cout << *c << ',';
							c++;
						}
					}
				mp.clear(), mpn.clear(), mpt.clear();
				cout << endl;
			}
			else cout << "No changes" << endl << endl;
		}
	}
	return 0;
}
