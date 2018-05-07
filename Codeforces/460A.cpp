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
	int n, m; cin >> n >> m;
	int res = 0;
	while (n) {
		n--; res++;
		n += bool(res%m == 0);
	}
	cout << res << endl;
	return 0;

}
