#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
string turn(string s) {
	string ret = "";
	sort(s.begin(), s.end());
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ')ret += s[i];
	}
	return ret;
}
int main()
{
	fast;
	int tc;
	cin >> tc;
	cin.ignore(); cin.ignore();
	while (tc--) {
		string s;
		vector<string>vs;
		while (getline(cin, s)) {
			if (s.empty())break;
			vs.push_back(s);
		}
		sort(vs.begin(), vs.end());
		for (int i = 0; i < vs.size(); i++) {
			for (int j = i+1; j < vs.size(); j++) {
				if(turn(vs[i])==turn(vs[j]))
					cout << vs[i] << " = " << vs[j] << endl;
			}
		}
		if(tc)
		cout << endl;
	}
	return 0;
}
