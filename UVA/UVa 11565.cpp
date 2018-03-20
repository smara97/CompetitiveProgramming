#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b, c;
		cin >> a >> b >> c;
		bool ok = 0;
		for (ll x = -1e2; x <= 1e2 && !ok; x++) {
			for (ll y = -1e2; y <= 1e2 && !ok; y++) {
				for (ll z = -1e2; z <= 1e2 && !ok; z++) {
					if (x != z && z != y && x != y) {
						if ((x + y + z) == a && (x*y*z) == b && ((y*y) + (x*x) + (z*z)) == c) {
							ok = 1;
							cout << x << ' ' << y << ' '<<z << endl;
						}
					}
				}
			}
		}
		if (!ok)cout << "No solution." << endl;
	}
	return 0;
}
