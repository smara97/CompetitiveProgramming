#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main()
{
	fast;
	string s,ss="";
	set<string>st;
	while (cin >> s) {
		//if (s == "DONE")break;
		if (!ss.empty()) {
			ss += s;
			s = ss; ss = "";
		}
		string tmp = "";
		for (int i = 0; i < s.length(); i++) {
			if (!isalpha(s[i]) && s[i] != '-') {
				if(tmp.size())st.insert(tmp);
				tmp = "";
				s.erase(i, 1), i--;
			}
			else {
				if (isalpha(s[i])) {
					if (s[i] < 97)s[i] = char((s[i] + 32));
				}
				tmp += s[i];
			}
		}
		if (s.size()) {

			if (s[s.length() - 1] == '-') {
				s.pop_back(); ss = s; tmp = ss;
			}
			else st.insert(tmp);
		}
	}
	set<string>::iterator it = st.begin();
	while (it != st.end()) {
		string sit = *it;
		if(!sit.empty())
			cout << *it << endl;
		it++;
	}
	return 0;
}
