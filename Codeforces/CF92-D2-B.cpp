#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
void File() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}
int main() {
	fast;
	string s;
	cin >> s;
	int res = 0, car = 0;
	for (int i = s.length()-1; i >= 0; i--) {
		res += bool(!i && car);
		if (i) {
				if (car == 1) {
					if (s[i] == '0')res+=2, car = 1;
					else res++;
				}
				else {
					if (s[i] == '1')res+=2, car = 1;
					else res++;
				}
		}
	}
	cout << res << endl;
	return 0;
}
