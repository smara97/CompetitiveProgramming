#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
ll memo[500][500] = { -1 };
ll m, ger[500][500],c;
int solve(int mon, int gr) {
	if (mon < 0)return INT_MIN;
	if (gr == c)return m - mon;
	if (memo[mon][gr] != -1)return memo[mon][gr];
	int ans = 0;
	for (int i = 1; i <= ger[gr][0]; i++)
		ans = max(ans, solve(mon - ger[gr][i], gr + 1));
	return memo[mon][gr] = ans;
}
int main()
{
	fast;
	int tc;
	cin >> tc;
	while (tc--) {
		memset(memo, -1, sizeof memo);
		cin >> m >> c;
		for (int i = 0; i < c; i++) {
			int g; cin >> g;
			ger[i][0] = g;
			for (int j = 1; j <= g; j++)
				cin >> ger[i][j];
		}
		int res = solve(m, 0);
		if (res <= 0)cout << "no solution" << endl;
		else cout << res << endl;
	}
	return 0;
} 
