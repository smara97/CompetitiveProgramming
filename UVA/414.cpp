#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main()
{
	fast;
	int n;
	while (cin >> n) {
		if (!n)break;
		string s;
		cin.ignore();
		vector<int>v; int mx = 0, res=0;
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			v.push_back(count(s.begin(),s.end(),'X'));
			mx = max(mx, v.back());
		}
		for (int i = 0; i <n; i++)
			res += (mx - v[i]);
		cout << res << endl;
	
	}
	return 0;
}
