#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
vector<ll>lu;
void luck(ll num) {
	if (num > 1e5)return;
	num *= 10;
	lu.push_back(num+4);
	luck(num + 4);
	lu.push_back(num+7);
	luck(num  +7);
}
int main() {
	fast;
	ll n; cin >> n;
	luck((ll)0);
	sort(lu.begin(), lu.end());
	for (int i = 0; i < lu.size(); i++) {
		if (n%lu[i] == 0) {
			cout << "YES" << endl; return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
