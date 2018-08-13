#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
int main() {
	fast;
	char A[1000][1000];
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> A[i][j];
	bool ok = 1;
	for (int i = 1; i <= n && ok; i++) {
		for (int j = 1; j <= n && ok; j++) {
			int cn = 0;
			cn += bool(A[i][j - 1] ==  'o');
			cn += bool(A[i][j +1] ==  'o');
			cn += bool(A[i+1][j] ==  'o');
			cn += bool(A[i-1][j] ==  'o');
			if (cn % 2)ok = 0;
		}
	}
	if (ok)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
