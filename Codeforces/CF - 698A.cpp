#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
int main()
{
	fast; int n, ans = 0;
	cin >> n;
	vector<int>days(n);
	for (int i = 0; i < n; i++)
		cin >> days[i];
	for (int i = 0; i < n - 1; i++) {
		if (!days[i])ans++;
		else {
			if (days[i] == 1) {
				if (days[i + 1] == 1)days[i + 1] = 0;
				else if (days[i + 1] == 3)days[i + 1] = 2;
			}
			else if (days[i] == 2) {
				if (days[i] == days[i + 1])days[i + 1] = 0;
				else if (days[i + 1] == 3)days[i + 1] = 1;
			}
		}
	}
	ans += bool(!days[n - 1]);
	cout << ans << endl;
	return 0;
}
