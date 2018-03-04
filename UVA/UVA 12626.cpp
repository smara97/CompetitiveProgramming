  #define _CRT_SECURE_NO_WARINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<cmath>
#include<bitset>
#include<iterator>
#include<queue>
#include<unordered_map>
#include<iomanip>
#include<functional>
#include<stack>
#include<sstream>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main() {

	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		int m = 0, i = 0, a = 0, g = 0, t = 0,r=0;
		for (int j = 0; j < s.length(); j++) {
			a += bool(s[j] == 'A'); r += bool(s[j] == 'R');
			g += bool(s[j] == 'G'); i += bool(s[j] == 'I');
			m += bool(s[j] == 'M'); t += bool(s[j] == 'T');
		}
		r /= 2; a /= 3;
		cout << min(a, min(g, min(r, min(t, min(m, i))))) << endl;
	}
	return 0;
}
