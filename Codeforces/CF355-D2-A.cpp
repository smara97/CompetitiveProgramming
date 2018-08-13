#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
int main() {
	fast;
	int n, k;
	cin >> n >> k;
	if (n > 1) {
		if (!k)cout << "No solution" << endl;
		else {
			cout << k; 
			for (int i = 0; i < n - 1; i++)cout << 0;
			cout << endl;
		}
	}
	else cout << k << endl;
	return 0;
}
