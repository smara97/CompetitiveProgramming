#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
bool cmp(char a, char b) {
	if (tolower(a) == tolower(b))
		return b > a;
	return tolower(b) > tolower(a);
}
int main()
{
	fast;
	int tc;
	cin >> tc;
	cin.ignore(); 
	while (tc--) {
		string s; cin >> s;
		sort(s.begin(), s.end(), cmp);
		do {
			cout << s << endl;
		} while (next_permutation(s.begin(), s.end(), cmp));
	}
	return 0;
}
