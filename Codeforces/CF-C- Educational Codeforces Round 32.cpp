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
	int b = 1, en = s.length();
	int res = 1e8;
	while (b <= en) {
		int mid = (b + en) / 2,tmp=1;
		int ch[100] = { 0 }, gt[100] = { 0 };
		for (int i = 0; i < mid; i++)ch[s[i] - 'a']++;
		for (int i = 0; i < 26; i++)
			if (ch[i] >= 1)gt[i]++;
		for (int i = mid; i < s.length(); i++) {
			ch[s[i] - 'a']++;
				ch[s[i - mid] - 'a']--; tmp++;
				for (int j = 0; j < 26; j++) {
					if (ch[j] >= 1)gt[j]++;
				}
		}
		bool ok = 0;
		for (int i = 0; i < 26; i++) {
			if (gt[i] == tmp)ok = 1;
		}
		if (ok)res = min(res, mid), en = mid - 1;
		else b = mid + 1;
	}
	cout << res << endl;
	m3lsh;
}
