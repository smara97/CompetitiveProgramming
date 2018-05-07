#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
int main()
{
	fast;
	int n;
	cin >> n;
	vector<ll>v(n);
	ll sum = 0,rem=0;
	for (int i = 0; i < n; i++)cin >> v[i], rem += v[i];
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < n; i++) {
		sum += v[i];
		if (sum > (rem - sum)) {
			cout << i + 1 << endl; return 0;
		}
	}
	return 0;

}
