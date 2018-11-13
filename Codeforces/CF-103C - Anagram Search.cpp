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

	int ocu[50] = { 0 }, ocus[50] = { 0 }, ques[300000] = { 0 };
int main() {
	fast;
	string s, ss;
	cin >> s >> ss;
	for (int i = 0; i < ss.length(); i++)ocu[ss[i] - 'a']++;
	int nxt = 0, prv = 0, que = 0;
	while (nxt < ss.length()) {
		if (isalpha(s[nxt]))
			ocus[s[nxt] - 'a']++;
		ques[nxt] = ques[max(0, nxt - 1)] + bool(s[nxt] == '?');
		nxt++;
	}
	int res = 0;
	bool fi = 1; int dif = 0;
	for (int i = 0; i < 50; i++) {
		if (ocus[i] > ocu[i]) {
			fi = 0;
		}
		else dif += (ocu[i] - ocus[i]);
	}
	if (fi)if (dif == ques[nxt - 1])res++;



	while (nxt < s.length()) {
		if (isalpha(s[prv]))
			ocus[s[prv] - 'a']--;
		dif = 0, fi = 1;
		if (isalpha(s[nxt]))
			ocus[s[nxt] - 'a']++;
		else ques[nxt]++;
		ques[nxt] += ques[nxt - 1];
		for (int i = 0; i < 50; i++) {
			if (ocu[i] < ocus[i])fi = 0;
			else dif += (ocu[i] - ocus[i]);
		}
		if (fi)res += bool(dif ==( ques[nxt] - ques[prv]));
		nxt++, prv++;
	}
	cout << res << endl;
	m3lsh;
}
