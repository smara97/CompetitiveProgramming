#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define m3lsh return 0;
typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int  dix[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int  diy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int main() {
	fast; 
	string s; cin >> s;
	vector<ll>val, oss;
	for (int i = 0; i < s.length(); i++) {
		int sign = 1;
		if (s[i] == '-')sign *= -1,i++;
		if (s[i] == '+')sign *= 1, i++;
		string num = "";int  j = i;
		for (j= i; j < s.length(); j++) {
			if (s[j] == 'x' || s[j]=='-' || s[j]=='+')break;
			num += s[j];
		}
		if (s[j] != 'x') {
			oss.push_back(0); continue;
		}
		stringstream ss; int nm;
		if (num.empty())num += '1';
		ss << num; ss >> nm;
		val.push_back(nm*sign); 
		if (s[j] != 'x') {
			i = j - 1;
			continue;
		}
		j++;
		num = ""; int os = 1;
		for (; j < s.length(); j++) {
			if (s[j] == '+' || s[j] == '-')break;
			num += s[j];
		}
		if (num.empty())num += '1';
		stringstream sx; int mn1;
		 i = j - 1;
		sx << num; sx >> mn1;
		oss.push_back(mn1);
	}
	string res = "";
	for (int i = 0; i < val.size(); i++) {
		int nm = val[i] * oss[i];
		if (nm > 0 && i)res += '+';
		stringstream sx; 
		sx << nm; string s; sx >> s;
		if (oss[i] == 1)res += s;
		else if (oss[i] == 0)continue;
		else {
			res += s;
			res.push_back('x');
			 stringstream sd;
			sd << (oss[i] - 1);
			string sf; sd >> sf;
			if (sf == "1")continue;
			res += sf;
		}
	}
	if (res.empty())cout << 0 << endl;
	cout << res << endl;
	m3lsh;
}
