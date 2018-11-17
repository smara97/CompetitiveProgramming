#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define m3lsh return 0;
typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int  dix[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int  diy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

int main() {
	fast;
	int n; cin >> n;
	vector<pair<int, int>>vp(n+1);
	for (int i = 0; i < n; i++)cin >> vp[i].first >> vp[i].second;
	int res = 0,prv=INT_MIN;
	for (int i = 0; i < n; i++) {
		if (vp[i].first - vp[i].second >= prv) {
			prv = vp[i].first +1; res++;
		}
		else {
			prv = vp[i].first + 1;
			if (i == n - 1)res++,prv=vp[i].first+vp[i].second+1;
			else {
				if (vp[i].first + vp[i].second < vp[i + 1].first) {
					res++; prv = vp[i].first + vp[i].second + 1;
				}
			}
		}
	}
	cout << res << endl;
	m3lsh;
}
