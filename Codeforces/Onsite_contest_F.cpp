#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int main()
{
	fast;
	string s;
	cin >> s; int sz = s.length();
	map<char, ll>mp;
	for (char a = 'a'; a <= 'z'; a++)
		cin >> mp[a];

	if (count(s.begin(), s.end(), '?')==sz) {

		cout << 0 << endl;
		for (int i = 0; i < sz; i++)
			cout << 'a';
		return 0;
	}
	if (s[0] == '?') {
		int j = 0;
		while (s[j] == '?')
			j++;
		while (j >= 1)
			s[j - 1] = s[j], j--;
	}
	if (s[sz - 1] == '?') {

		int j = sz-1;
		while (s[j] == '?')
			j--;
		while (j <sz-1)
			s[j+1] = s[j], j++;
	}
	for (int i = 0; i < sz; i++) {
		if (s[i] == '?') {
			char x = s[i - 1],y;
			int j = i+1;
			while (s[j] == '?')j++;
			y = s[j];
			ll mn = INT_MAX; char rpc;
			for (char a = 'a'; a <= 'z'; a++) {
				ll tmp = abs(mp[y] - mp[a]) + abs(mp[x] - mp[a]);
				if ((tmp < mn))rpc = a,mn=tmp;
			}
			while (i < j)
				s[i] = rpc, i++;
		}
	}
	ll sum = 0;
	for (int i = 0; i < sz - 1; i++)
		sum += abs(mp[s[i]] - mp[s[i + 1]]);
	cout << sum << endl;
	cout << s << endl;
	return 0;
}
