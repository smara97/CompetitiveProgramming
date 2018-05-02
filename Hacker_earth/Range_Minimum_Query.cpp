#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
vector<ll>seg(1e7, INT_MAX);
vector<ll>inp;
void build(int l, int r, int po) {
	if (r == l) {
		seg[po] = inp[l];
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, po * 2 + 1);
	build(mid+1, r, po * 2 + 2);
	seg[po] = min(seg[po * 2 + 1], seg[po * 2 + 2]);
}
int mn(int l, int r, int po, int l1, int r1) {
	if (l1 <= l && r1 >= r)return seg[po];
	if (l1 > r || r1 < l)return INT_MAX;
	int mid = (l + r) / 2;
	return min(mn(l, mid, po * 2 + 1, l1, r1), mn(mid + 1, r, po * 2 + 2, l1, r1));
}
void updata(int l, int r, int po, int ind, int v) {
	if (l == r) {
		seg[po] = v;
		inp[ind] = v;
		return;
	}
	int mid = (l + r) / 2;
	if (ind <= mid) updata(l, mid, po * 2 + 1, ind, v);
	else updata(mid + 1, r, po * 2 + 2, ind, v);
	seg[po] = min(seg[po * 2 + 1], seg[po * 2 + 2]);
}
int main()
{
	fast; 
	int n, q;
	cin >> n >> q;
	inp = vector<ll>(n);
	for (int i = 0; i < n; i++)cin >> inp[i];
	build(0, n - 1, 0);

	while (q--) {
		char x; int l, r;
		cin >> x >> l >> r;
		if (x == 'q')cout << mn(0,n-1,0,l - 1, r - 1) << endl;
		else updata(0, n - 1, 0, l - 1, r);
			
	}
	return 0;
}
