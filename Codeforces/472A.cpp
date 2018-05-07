#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
bitset<1000009>bt;
void prime() {
	ll num = 1e6;
	bt.set();
	bt[1] = bt[0] = 0;
	for (ll i = 2; i*i <= 1e6; i++) {
		if (bt[i]) {
			for (ll j = i*i; j <= 1e6; j += i)bt[j] = 0;
		}
	}
}
int main()
{
	fast;
	int n; cin >> n;
	prime();
	for (int i = 2; i <n; i++) {
		if (!bt[i] && !bt[n - i]) {
			cout << i << ' ' << n - i;
			return 0;
		}
	}
	return 0;

}
