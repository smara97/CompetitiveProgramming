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
int chs[100] = { 0 }, chss[100] = { 0 }, bas[100] = {0};
int main(){
	fast;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s, ss;
	cin >> s >>ss;
	for (int i = 0; i < ss.length(); i++) {
		chs[s[i] - 'A']++; bas[ss[i] - 'A']++;
		chss[ss[i] - 'A']++;
	}
	int chanin[100], chande[100];
	for (int i = 0; i < 26; i++) {
		chanin[i] = max(0, chs[i] - chss[i]);
		chande[i] = max(0, chss[i] - chs[i]);
	}
	int res = 0;
	for (int i = 0; i < ss.length(); i++) {
		if (chanin[s[i] - 'A'] > 0) {
			if (bas[s[i] - 'A']) {
				int ch = s[i] - 'A';
				for (int j = 0; j < ch; j++) {
					if (chande[j] > 0 && bas[j]) {
						ch = j; chande[j]--; break;
					}
				}
				if (ch != (s[i] - 'A')) {
					res++; chanin[s[i] - 'A']--;
				}
				bas[ch]--;
				s[i] = char('A' + ch);
			}
			else {
				int ch = s[i] - 'A';
				for (int j = 0; j < 26; j++) {
					if (chande[j] > 0 && bas[j]) {
						ch = j; chande[j]--; break;
					}
				}
				res++; bas[ch]--;
				chanin[s[i] - 'A']--;
				s[i] = char(ch + 'A');
			}
		}
	}
	cout << res << endl;
	cout << s << endl;
	m3lsh;
}
