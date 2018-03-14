#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
bool ad[509][509];
int main() {
	fast;
	int n, m,q; 
	while (cin >> n >> m >> q && n && m ) {
		ll res = 0; memset(ad, 0, sizeof(ad));
		int x, y, xx, yy;
		while (q--) {
			cin >> x >> y >> xx >> yy;
				for (int i = min(x,xx); i <= max(x,xx); i++)
					for (int j = min(y, yy); j <= max(y, yy); j++)
						ad[i][j] = 1;
		}
		res = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				res += bool(!ad[i][j]);

		if (!res)cout << "There is no empty spots." << endl;
		else if (res == 1)cout << "There is one empty spot." << endl;
		else cout << "There are " << res << " empty spots." << endl;
	}
	return 0;
}
