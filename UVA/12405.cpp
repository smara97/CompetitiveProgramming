#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main()
{
	fast;
	int  tc, cn = 1;;
	cin >> tc;
	while (tc--) {
		int n; cin >> n;
		string s; cin >> s;
		s += '#';
		cout << "Case "<<cn++ << ": ";
		if (n < 3) {
			if (s[0] == '.' || s[1] == '.')cout << 1 << endl;
			else cout << 0 << endl;
			continue;
		}
		int res = 0;
		for (int i = 0; i < s.length() - 2; i++) {
			if (s[i + 1] == '.'&&s[i] == '.' && s[i+2]=='.') {
				res++; s[i] = '#';
				s[i+1] = '#'; s[i+2] = '#';
			}
			else if (s[i] == '.' && s[i + 1] == '.') {
				res++; s[i] = '#', s[i + 1] = '#';
			}
			else if (s[i] == '.' && s[i + 2] == '.') {
				res++; s[i] = '#', s[i + 2] = '#';
			}
		}

		for (int i= 0; i < s.length() - 1; i++) {

			if (s[i] == '.') {
				res++;
				if (s[i + 1] == '.')s[i + 1] = '#';
			}
		}
		cout << res << endl;
	}
	return 0;
}
