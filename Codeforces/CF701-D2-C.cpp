#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main()
{
	fast;
	int n; cin >> n;
	string s;
	cin >> s; set<char>st(s.begin(), s.end());
	int k = st.size();
	int p1 = 0, p2 = 0;
	map<char, int>mp;
	set<char>se;
	int res = INT_MAX;
	while (p2 <= n) {
		if (se.size() == k) {
			res = min(p2 - p1, res);
				mp[s[p1]]--;
				if (mp[s[p1]] <= 0)se.erase(s[p1]);
			p1++;
		}
		else {
				se.insert(s[p2]);
				mp[s[p2]]++;
			p2++;
		}
	}
	cout << res << endl;
	return 0;
}
