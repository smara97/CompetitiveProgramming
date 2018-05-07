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
	int n, t; cin >> n >> t;
	string s;
	cin >> s;
	while (t--) {
		for (int i = 0; i < s.length() - 1; i++) {
			if (s[i] == 'B'&&s[i + 1] == 'G')swap(s[i], s[i + 1]),i++;
		}
	}
	cout << s << endl;
	return 0;

}
