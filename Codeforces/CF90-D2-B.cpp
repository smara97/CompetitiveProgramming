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
	int n, m;
	cin >> n >> m;
	char gr[110][110];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> gr[i][j];
	string res = "";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x = gr[i][j];
			int cnt = 0;
			for (int k = 0; k < n; k++)
				cnt += bool(x == gr[k][j]);
			for (int k = 0; k < m; k++)
				cnt += bool(x == gr[i][k]);
			if (cnt == 2)res += x;
		}
	}
	cout << res << endl;
	return 0;
}
