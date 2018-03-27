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
	int tc;
	cin >> tc;
	while (tc--) {
		string s,res="";
		cin >> s;
		stack<char>stp, stop;
		for (int i = 0; i < s.length(); i++) {
			if (isalpha(s[i]))
				res += s[i], s.erase(i, 1), i--;
			else {
				if (s[i] == ')') {
					s[i] = 'A';
					int j = i - 1;
					while (j >= 0 && s[j] != '(') {
						if (!isalpha(s[j]))res += s[j], s[j] = 'A';
						j--;
					}
					if (j >= 0)s[j] = 'A';
				}
			}
		}
		cout << res << endl;
	}

	return 0;
}
