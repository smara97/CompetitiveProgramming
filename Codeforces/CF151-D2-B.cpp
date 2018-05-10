#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
bool ad[1001][1001];
bool tax(string s) {
	set<char>st(s.begin(), s.end());
	return (st.size() == 2);
}
bool piza(string s) {
	return (s[0] > s[1] && s[1] > s[3] && s[3] > s[4] && s[4] > s[6] && s[6] > s[7]);
}
int main()
{
	fast;
	int n;
	cin >> n;
	vector<string>v;
	int mxp = 0, mxg = 0, mxt = 0;
	map<string, int>mp;
	map<string, int>mp1;
	map<string, int>mp2;
	for (int i = 0; i < n; i++) {
		int f; string s;
		cin >> f >> s;
		v.push_back(s);
		int piz = 0, txi = 0, gir = 0;
		for (int j = 0; j < f; j++) {
			string ss;
			cin >> ss;
			if (tax(ss)) ++txi, mxt = max(mxt, txi);
			else if (piza(ss)) ++piz,mxp=max(mxp,piz);
			else ++gir,mxg=max(mxg,gir);
		}
		mp[s] = txi;
		mp1[s] = piz;
		mp2[s] = gir;
	}
	vector<string>pt, pp, pg;
	for (int i = 0; i < n; i++) {
		if (mp[v[i]] >= mxt) {
			pt.push_back(v[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (mp1[v[i]] >= mxp) {
			pp.push_back(v[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (mp2[v[i]] >= mxg) {
			pg.push_back(v[i]);
		}
	}
	cout << "If you want to call a taxi, you should call: ";
	for (int i = 0; i < pt.size(); i++) {
		if (i != pt.size() - 1)cout << pt[i] << ", ";
		else cout << pt[i] << '.' << endl;
	}
	cout<<"If you want to order a pizza, you should call: ";
	for (int i = 0; i < pp.size(); i++) {
		if (i != pp.size() - 1)cout << pp[i] << ", ";
		else cout << pp[i] << '.' << endl;
	}
	cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
	for (int i = 0; i < pg.size(); i++) {
		if (i != pg.size() - 1)cout << pg[i] << ", ";
		else cout << pg[i] << '.' << endl;
	}
	return 0;
}
