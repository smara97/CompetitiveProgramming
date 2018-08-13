#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
int main() {
	fast;
	int n, m;
	cin >> n >> m;
	vector<string>vs(n);
	vector<int>vm(m);
	for (int i = 0; i < n; i++) {
		cin >> vs[i];
		for (int j = 0; j < m; j++) {
			vm[j] = max(vm[j], vs[i][j] - '0');
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		bool ok = 0;
		for (int j = 0; j < m; j++) {
			if (vs[i][j]-'0' == vm[j])ok = 1;
		}
		res += bool(ok);
	}
	cout << res << endl;
	return 0;
}
