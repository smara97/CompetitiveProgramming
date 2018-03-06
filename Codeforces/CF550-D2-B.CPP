#define _CRT_SECURE_NO_WARINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<cmath>
#include<bitset>
#include<iterator>
#include<queue>
#include<unordered_map>
#include<iomanip>
#include<functional>
#include<stack>
#include<sstream>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main() {
	int n, l, r, x;
	cin >> n >> l >> r >> x;
	vector<int>v(n); set<vector<int>>sv;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	ll ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		ll sum = 0, np = 0;; int mn = INT_MAX, mx = INT_MIN;
		for (int j = 0; j < n; j++) {
			if (i&(1 << j)) {
				sum += v[j]; np++;
				mn = min(mn, v[j]); mx = max(mx, v[j]);
			}
		}
		ans += bool(sum >= l&&sum <= r && abs(mn - mx ) >= x && np>=2);
	}
	cout << ans << "\n";
	return 0;
}
