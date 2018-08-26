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
	int n; cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	cin >> n;
	vector<int>vv(n);
	for (int i = 0; i < n; i++)cin >> vv[i];
	sort(v.begin(), v.end());
	sort(vv.begin(), vv.end());
	int res = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < vv.size(); j++) {
			if (abs(vv[j] - v[i]) <= 1) {
				res++; vv[j] = 1e5; break;
			}
		}
	}
	cout << res << endl;
	return 0;
}
