#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
void File() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}
int main() {
	fast;
	int n; cin >> n;
	map<int, vector<int>>mp;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mp[x].push_back(i);
	}
	vector<pair<int, int>>pu;
	for (auto e : mp) {
		int num = e.first; int occ = 0, cnt = 0;
		map<int, int>ma;
		if (e.second.size() == 1) {
			pu.push_back({ num,0 }); continue;
		}
		for (int i = 0; i < e.second.size(); i++) {
			if (i) {
				ma[e.second[i] - e.second[i - 1]]++;
			}
		}
		map<int, int>::iterator it= ma.begin();
		if (ma.size() == 1)pu.push_back({ num,it->first });
	}
	cout << pu.size() << endl;
	for (auto e : pu)cout << e.first << ' ' << e.second << endl;
	return 0;
}
