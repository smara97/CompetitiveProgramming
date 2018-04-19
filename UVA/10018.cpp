#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
string trn(ll num) {
	stringstream ss; string s;
	ss << num; ss >> s;
	return s;
}
ll trnn(string s) {
	stringstream ss; ll num;
		ss << s; ss >> num;
		return num;
}
int main()
{
	fast;
	int n;
	cin >> n;
	while (n--) {
		string s; int cnt = 0;
		cin >> s;
		string ss = s; reverse(ss.begin(), ss.end());
		while (s != ss) {
			ll x = trnn(s), y=trnn(ss);
			x += y;
			s = trn(x);
			ss = s;
			reverse(ss.begin(), ss.end());
			cnt++;
		}
		cout << cnt << ' ' << s << endl;
	}
	return 0;
}
