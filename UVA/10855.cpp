#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
using namespace std;
typedef long long ll;
int n, nn;
char  gris[1000][1000];
vector<vector<char>>gri;
bool valid(int i, int j,int ii,int jj) {
	return i >= 0 && i < nn&&ii >= 0 && ii < n&&j >= 0 && j < nn&&jj >= 0 && jj < n;
}
int cnt() {
	int res = 0;
	for (int i = 0; i < nn; i++) {
		for (int j = 0; j < nn; j++) {
			if (gri[i][j] == gris[0][0]) {
				int ok = 1;
				for (int k = 0; k < n && ok; k++) {
					for (int kk = 0; kk < n && ok; kk++) {
						if (valid(k + i, kk + j, k, kk))
							ok = bool(gri[i + k][j + kk] == gris[k][kk]);
						else ok = 0;
					}
				}
				res += bool(ok);
			}
		}
	}
	return res;
}
int main() {
	fast;
	while (cin >> nn >> n) {
		if (!n && !nn)break;
		gri = vector<vector<char>>(nn, vector<char>(nn));
		for (int i = 0; i < nn; i++)
			for (int j = 0; j < nn; j++)
				cin >> gri[i][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> gris[i][j];
		int a = cnt();
		int ans[4] = { a };
		char rot[1000][1000];
		for (int t = 0; t < 3; t++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					rot[j][n - i - 1] = gris[i][j];
				}
			}
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					gris[i][j] = rot[i][j];
			ans[t + 1] = cnt();
		}
		cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << endl;
	}
	return 0;
}
