#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
vector<ll>seg(1e7, 0), inp;
void build(int l, int r, int po) {
	if (l == r) {
		seg[po] = inp[l];
		return;
	}
	int mid = (l + r) / 2;
	build(l,mid, po * 2 + 1);
	build(mid + 1, r, po * 2 + 2);
	// requairments min,sum,max;
}
void updata(int l, int r, int po, int ind, int v) {
	if (l == r) {
		seg[po] = inp[ind] = v;
		return;
	}
	int mid = (l + r) / 2;
	if (mid > ind)updata(l, mid, po * 2 + 1, ind , v);
	else updata(mid + 1, r, po * 2 + 2, ind, v);
	// requairments min,sum,max;
}
// partial(right,lest) total(return segment[po]) not ovarlab return not;
int main()
{
	fast;
	return 0;
}
