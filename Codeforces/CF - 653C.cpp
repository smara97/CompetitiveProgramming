#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
vector<ll>vn;
vector<ll>v;
int bin(ll itm) {
	int b = 0, en = vn.size() - 1, ind;
	while (b <= en) {
		int mid = (b + en) / 2;
		if (vn[mid] == itm) 
			return mid;
		else if (vn[mid] > itm)en = mid - 1;
		else b = mid + 1;
	}
}
bool ok() {
	for (int i = 0; i < v.size()-1; i++) {
		if (i % 2==1) {
			if (v[i] <= v[i + 1])
				return 0;
		}
		else {
			if (v[i] >= v[i + 1])return 0;
		}
	}
	return 1;
}
int main()
{
	fast;
	int n;
	cin >> n;
	ll mx = 0;
	v=vector<ll>(n);
	for (int i = 0; i < n; i++)cin >> v[i], mx = max(mx, v[i]);
	vector<vector<ll>>ad(mx+1);
	set<ll>st;
	map<pair<ll, ll>, bool>mp;
	for (int i = 0; i < n; i++)ad[v[i]].push_back(i),st.insert(v[i]);
	for (auto e : st)vn.push_back(e);
	ll res = 0;
	for (int i = 0; i < n-1; i++) {
		int ind = bin(v[i+1]);
		if (i % 2==1) {
			ind++;
			while (ind <vn.size()) {
				if (!mp[{min(vn[ind], v[i]), max(vn[ind], v[i])}]) {
					for (int j = 0; j < ad[vn[ind]].size(); j++) {
						swap(v[ad[vn[ind]][j]], v[i]);
						res += ok();
						swap(v[ad[vn[ind]][j]], v[i]);
					}
					mp[{min(vn[ind], v[i]), max(vn[ind], v[i])}] = 1;
				}
				ind++;
			}
		}
		else {
			ind--;
			while (ind >=0) {
				if (!mp[{min(vn[ind], v[i]), max(vn[ind], v[i])}]) {
					for (int j = 0; j < ad[vn[ind]].size(); j++) {
						swap(v[ad[vn[ind]][j]], v[i]);
						res += ok();
						swap(v[ad[vn[ind]][j]], v[i]);
					}
					mp[{min(vn[ind], v[i]), max(vn[ind], v[i])}] = 1;
				}
				ind--;
			}
		}
	}
	cout << res << endl;
	return 0;
} 
