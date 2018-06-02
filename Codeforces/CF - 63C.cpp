#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
struct st {
	int a, b, c;
};
int main()
{
	fast;
	int n;
	cin >> n;
	vector<string>vs(n);
	vector<pair<int, int>>vp(n);
	for (int i = 0; i < n; i++) {
		cin >> vs[i];
		cin >> vp[i].first>>vp[i].second;
	}
	int cnt = 0; string res;
	for (char i = '0'; i <= '9'; i++) {
		for (char j = '0'; j <= '9'; j++) {
			for (char k = '0'; k <= '9'; k++) {
				for (char l = '0'; l <= '9'; l++) {
					string s = ""; s = i;
					s += j; s += k; s += l;
					set<char>st(s.begin(), s.end());
					if (st.size() == 4) {
						bool no = 0,mins=0;
						for (int ii = 0; ii < n; ii++) {
							int x = vp[ii].first, y = vp[ii].second;
							for (int jj = 0; jj < 4; jj++) {
								x -= bool(s[jj] == vs[ii][jj]);
								if (s[jj] != vs[ii][jj]) {
									bool oo = 0;
									for (int j2 = 0; j2 < 4; j2++) {
										if (j2 != jj) {
											if (s[jj] == vs[ii][j2])y--;
										}
									}
								}
							}
							if (x || y) {
								no=1; break;
							}
						}
						if (!no) {
							cnt++, res = s;
						}
					}
				}	 
			}
		}
	}
	if (cnt == 1)cout << res << endl;
	else if (cnt > 1)cout << "Need more data" << endl;
	else cout << "Incorrect data" << endl;
	return 0;
} 
