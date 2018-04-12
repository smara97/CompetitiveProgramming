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
	int n, m;
	cin >> n >> m;
	if (n % 2) {
		cout << n <<  endl;
		return 0;
	}
	vector<string>vs(n+1);
	for (int i = 0; i < n; i++) {
		string s = "";
		for (int j = 0; j < m; j++) {
			char x; cin >> x; s += x;
		}
		vs[i] = s;
	}
	while (!(n % 2)) {
		bool plan = 1;
		for (int i = 0; i < n / 2; i++) {
			if (vs[i] != vs[n-i-1])plan = 0;
		}
		if (plan)n /= 2;
		else break;
	}
	cout << n << endl;
	return 0;
}
