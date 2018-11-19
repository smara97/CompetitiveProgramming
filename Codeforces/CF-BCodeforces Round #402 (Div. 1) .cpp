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
	string s, t;
	cin >> s >> t;
	vector<int>v((int)s.length());
	for (int i = 0; i < s.length(); i++)cin >> v[i];
	int res = 0;
	int b = 0, en = s.length();
	while (b <= en) {
		int mid = (b + en) / 2;
		string op = ""; int ind = 0;
		vector<int>indx;
		for (int i = mid; i < s.length(); i++)indx.push_back(v[i]);
		sort(indx.begin(), indx.end());
		for (int i = 0; i <indx.size(); i++) {
			op += s[indx[i]-1];
			if(ind<t.length())
				if (op.back() == t[ind])ind++;
		}
		if (ind == t.length())b = mid + 1,res=mid;
		else en = mid - 1;
	}
	cout << res << endl;
	m3lsh;
}
