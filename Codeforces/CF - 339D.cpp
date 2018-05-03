#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
vector<ll>segment(1 << 18);
vector<ll>inp(1 << 18);
bool build(int l, int r, int po) {
	if (l == r) {
		segment[po] = inp[l];
		return 1;
	}
	int mid = (l + r) / 2;
	bool lif = build(l, mid, po * 2 + 1),rig= build(mid+1, r, po * 2 + 2);
	if (lif && rig) {
		segment[po] = segment[po * 2 + 1] | segment[po * 2 + 2];
		return 0;
	}
	segment[po] = segment[po * 2 + 1] ^ segment[po * 2 + 2];
	return 1;

}
bool updata(int l, int r, int po, int ind, int v) {
	if (l == r) {
		segment[po] = v;
		inp[ind] = v;
		return 1;
	}
	int mid = (l + r) / 2;
	bool lif = 0, rig = 0;
	if (ind <= mid) lif=updata(l, mid, po * 2 + 1, ind, v);
	else rig=updata(mid + 1, r, po * 2 + 2, ind, v);
	if (lif || rig) {
		segment[po] = segment[po * 2 + 1] | segment[po * 2 + 2];
		return 0;
	}
	segment[po] = segment[po * 2 + 1] ^ segment[po * 2 + 2];
	return 1;
}
int main()
{
	fast; 
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < (1 << n); i++)cin >> inp[i];
	build(0, (1 << n) - 1, 0);
	while (q--) {
		int p, b; cin >> p >> b;
		updata(0, (1 << n) - 1, 0, p - 1, b);
		cout << segment[0] << endl;
	}
	return 0;
}
