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
unsigned long long a, b;
int main() {
	ll n, k;
	cin >> n >> k;
	ll b = 1, e = 1e17; ll ans = 1e17;
	while (b <= e) {
		ll mid = (b + e) / 2;
		ll sum = mid,temp=mid,kp=k;
		while (temp >= kp) {
			sum += (temp / kp); kp *= k;
		}
		if (sum >= n) {
			ans = min(ans, mid);
			e = mid - 1;
		}
		else b = mid + 1;
	}
	cout << ans << "\n";
	return 0;
}
