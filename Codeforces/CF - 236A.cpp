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
	string s; cin >> s;
	set<char>st(s.begin(), s.end());
	if (st.size() % 2)cout << "IGNORE HIM!" << endl;
	else cout << "CHAT WITH HER!" << endl;
	return 0;
}
