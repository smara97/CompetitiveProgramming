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
int chs[100] = { 0 }, chss[100] = { 0 }, bas[100] = {0};
int main(){
	fast;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x, y; cin >> x >> y;
	vector<pair<int, int>>vp;
	int mi = min(x, y);
	for (int i = mi; i >= 0; i--) {
		vp.push_back({ i,mi - i });
	}
	sort(vp.rbegin(), vp.rend());
	cout << int(vp.size()) << endl;
	if (vp[0].first < x)
		for (int i = 0; i < vp.size(); i++)
			cout << vp[i].second <<' '<< vp[i].first << endl;
	else
		for (int i = 0; i < vp.size(); i++)
			cout << vp[i].first <<' '<< vp[i].second << endl;
	m3lsh;
}
