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
		int n; ll cnt = 0;
		cin >> n;
		vector<int>v;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			for (int j = 0; j < v.size(); j++)
				cnt += bool(x >= v[j]);
			v.push_back(x);
		}
		cout << cnt << endl;
	}

	return 0;
}
