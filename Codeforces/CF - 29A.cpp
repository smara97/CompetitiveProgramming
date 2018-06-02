#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
int main()
{
	fast;
	int n;
	cin >> n;
	vector<pair<ll,ll>>v(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[i].first = x, v[i].second = x + y;
	}
	for (int i = 0; i < n; i++) {
		for(int j=i+1;j<n;j++){
			if (v[i].first == v[j].second && v[j].first==v[i].second) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
} 
