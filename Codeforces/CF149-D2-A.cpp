#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
int main() {
	fast;
	int k;
	cin >> k;
	vector<int>v(12);
	for (int i = 0; i < 12; i++)cin >> v[i];
	sort(v.rbegin(), v.rend());
	int sum = 0,i;
	for ( i = 0; i < 12 && sum<k; i++)sum += v[i];
	if (sum >= k)cout << i << endl;
	else cout << -1 << endl;
	return 0;
}
