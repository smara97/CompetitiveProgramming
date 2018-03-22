#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main()
{
	fast;
	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (v[i] > v[j]) {
					swap(v[i], v[j]); res++;
				}
			}
		}
		cout << "Optimal train swapping takes " << res << " swaps." << endl;
	}
	return 0;
}
