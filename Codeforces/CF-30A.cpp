#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
int main()
{
	fast;
	ll a, b, n,i=-30;
	cin >> a >> b >> n;
	if (n % 2 == 0)i = 0;
	if ((a*b) < 0) {
		if (a > 0)a *= -1,b*=-1;
	}
	else b = abs(b), a = abs(a);
	for (; (pow(i, n)) <= b; i++) {
		if (a*pow(i, n) == b) {
			cout << i << endl;
			return 0;
		}
	}
	cout << "No solution" << endl;
	return 0;
} 
