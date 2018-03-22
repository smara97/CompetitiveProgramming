#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main() {
	int tc;
	cin >> tc; int cnt = 1;
	while (tc--) {
		int n, p, q;
		cin >> n >> p >> q;
		vector<int>grm(n);
		for (int i = 0; i < n; i++)
			cin >> grm[i];
		sort(grm.begin(), grm.end());
		ll res = 0, tgrm = 0;
		for (int i = 0; i < min(n, p); i++) {
			if (tgrm + grm[i] > q)break;
			tgrm += grm[i], res++;
		}
		cout << "Case " << cnt++ << ": " << res << endl;
	}
	return 0;
}
