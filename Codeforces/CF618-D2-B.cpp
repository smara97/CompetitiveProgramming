#define _CRT_SECURE_NO_WARINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<cmath>
#include<bitset>
#include<iterator>
#include<queue>
#include<unordered_map>
#include<iomanip>
#include<functional>
#include<stack>
#include<sstream>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int main() {
	fast;
	int n;
	cin >> n;
	vector<int>per(n + 1);
	vector<vector<int>>ad(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> ad[i][j];
	for (int i = 1; i <= n; i++) {
		vector<pair<int, int>>vp;
		
		for (int r = 1, cnt = 0; r <= n; r++, cnt = 0) {
			for (int c = 1; c <= n; c++)
				cnt += bool(ad[r][c] == i);
			vp.push_back({ cnt,r });
		}
		sort(vp.rbegin(), vp.rend());
		if (vp[0].first == 0) continue;
		per[vp[0].second] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (!per[i])per[i] = n;
		cout << per[i] << ' ';
	}
		
	cout << endl;
	return 0;
}
