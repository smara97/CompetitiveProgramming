#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
void File() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
double dis(int x, int y, int xx, int yy) {
	return double(sqrt(pow(x - xx, 2) + pow(y - yy, 2)));
}
vector<int>v, seg, lazy;
void build(int l, int h, int po) {
	if (l == h) {
		seg[po] = v[l];
		return;
	}
	int mid = (l + h) / 2;
	build(l, mid, po * 2 + 1);
	build(mid + 1, h, po * 2 + 2);
	seg[po] = min(seg[po * 2 + 2], seg[po * 2 + 1]);
}
void updata(int l, int h, int lq, int hq, int po, int va,int x) {
	if (l > h)return;
	if (lazy[po] != 0) {	
		seg[po] += lazy[po];
		if (l != h) {
			lazy[po * 2 + 1] += lazy[po];
			lazy[po * 2 + 2] += lazy[po];
		}
		lazy[po] = 0;
	}
	 if (seg[po]>x) {
			seg[po] += va;
			if (l != h) {
				lazy[po * 2 + 1] += va;
				lazy[po * 2 + 2] += va;
			}
		return;
	}
	 if (l == h)return;
	int mid = (l + h) / 2;
	updata(l, mid, lq, hq, po * 2 + 1, va,x);
	updata(mid+1, h, lq, hq, po * 2 + 2, va,x);
	seg[po] = min(seg[po * 2 + 1], seg[po * 2 + 2]);
}
int mnq(int l, int h, int lq, int hq, int po) {
	if (l > h) {
		return INT_MAX;
	}
	if (lazy[po] != 0) {
		seg[po] += lazy[po];
		if (l != h) {
			lazy[po * 2 + 1] += lazy[po];
			lazy[po * 2 +2] += lazy[po];
		}
		lazy[po] = 0;
	}
	if (lq > h || hq < l)return INT_MAX;
	else if (lq <= l && hq >= h)return seg[po];
	int mid = (l + h) / 2;
	int mn=mnq(l, mid, lq, hq, po * 2 + 1);
	int mnn=mnq(mid+1, h, lq, hq, po * 2 + 2);
	return  min(mn, mnn);
}	
int main() {
   fast;
   int n; cin >> n;
   v = vector<int>(n);
   lazy = seg = vector<int>(4 * n,0);
   for (int i = 0; i < n; i++)cin >> v[i];
   int q; cin >> q;
   build(0, n - 1, 0);
   while (q--) {
	   ll x; cin >> x;
		   updata(0, n - 1, 0, n-1, 0, -1,x);
   }
   for (int i = 0; i < n; i++)cout << mnq(0, n - 1, i, i, 0) << ' ';
   cout << endl;
   return 0;
}
