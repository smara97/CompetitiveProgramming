#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
int main()
{
	fast;
	int n, d;
	cin >> n >> d;
	vector<ll>v(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(i!=j)
				res += bool(abs(v[i] - v[j]) <= d);
		}
	}
	cout << res << endl;
	return 0;
} 
