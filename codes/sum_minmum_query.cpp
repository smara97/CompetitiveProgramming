#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
vector<int>seg(1e6,0);
vector<int>v;
void build(int l, int r, int po) {
	if (l == r) {
		seg[po] = v[l]; return;
	}
	int mid = (l + r) / 2;
	build(l, mid, po * 2 + 1);
	build(mid + 1, r, po * 2 + 2);
	seg[po] = seg[po * 2 + 1] + seg[po * 2 + 2];
}
int sq(int l, int r, int ll, int rr, int po) {
	if (ll <= l && rr >= r) {
		return seg[po];
	}
	else if (ll>r || rr<l)return 0;
	int mid = (l + r) / 2;
	return (sq(mid + 1, r, ll, rr, po * 2 + 2)+ sq(l, mid, ll, rr, po * 2 + 1));

}
int main()
{
	fast;
	int n, q;
	cin >> n >> q;
	v=vector<int>(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	build(0, n - 1, 0);
	while (q--) {
		int l, r; 
		cin >> l >> r;
		cout << sq(0, n - 1, l - 1,  r - 1, 0) << endl;
	}
	return 0;
}
