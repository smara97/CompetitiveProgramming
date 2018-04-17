#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
vector<ll>vm,tmp,qu;


vector<ll> insect(vector<ll>vv) {
	for (int i = 1; i < vv.size(); i++) {
		int j = i - 1;
		ll tmp = vv[i];
		while (j >= 0 && vv[j] > tmp)vv[j+1] = vv[j],j--;
		vv[j + 1] = tmp;
	}
	return vv;
}



vector<ll> select(vector<ll>vv) {
	for (int i = 0; i < vv.size(); i++)
		for (int j = i + 1; j < vv.size(); j++)
			if (vv[i] > vv[j])swap(vv[i], vv[j]);
	return vv;
}


vector<ll>bubble(vector<ll>vv) {
	for (int i = vv.size() - 1; i >= 0; i--)
		for (int j = i - 1; j >= 0; j--)
			if (vv[i] < vv[j])swap(vv[i], vv[j]);
	return vv;
}
int piovt(int l, int r) {
	int ppv = qu[l],indppv=l;
	while (l < r) {
		if (l == indppv) {
			if (ppv > qu[r]) {
				swap(qu[indppv], qu[r]);
				indppv = r;
			}
			else r--;
		}
		else {
			if (ppv < qu[l]) {
				swap(qu[indppv], qu[l]);
				indppv = l;
			}
			else l++;
		}
	}
	return indppv;
}

void quck(int l,int r) {
	if (l < r) {
		int indpvt = piovt(l, r);
		quck(l, indpvt-1);
		quck(indpvt + 1, r);
	}
}

void nmerg(int l1, int r1, int l2,int r2) {
	for (int i = l1; i <= r2; i++)tmp[i] = vm[i];
	int ind = l1;
	while (l1 <= r1 && l2 <= r2) {
		if (tmp[l1] <= tmp[l2]) {
			vm[ind++] = tmp[l1];
			l1++;
		}
		else {
			vm[ind++] = tmp[l2]; l2++;
		}
	}
	while (l1 <= r1)vm[ind++] = tmp[l1++];
	while (l2 <= r2)vm[ind++] = tmp[l2++];
}
void merg(int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		merg(l, mid);
		merg(mid + 1, r);
		nmerg(l, mid, mid + 1, r);
	}
}


int bainry(vector<ll>vv, ll itm) {
	int str = 0, fin = vv.size() - 1;
	while (str <= fin) {
		int mid = (str + fin) / 2;
		if (vv[mid] == itm)return mid;
		if (vv[mid] > itm)fin = mid - 1;
		else str = mid + 1;
	}
	return -1;
}


int main()
{
	fast;
	int n;
	cin >> n;
 	vector<ll>v(n);
	vm = vector<ll>(n);
	tmp = vector<ll>(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<ll>se(n);
	se = v;
	se=select(v); 
	vector<ll>vv(n);
	vv = v;
	vv=insect(vv);
	for (int i = 0; i < n; i++)cout << se[i] << ' ';
	cout << endl;
	for (int i = 0; i < n; i++)cout << vv[i] << ' ';
	cout << endl;
	vm = v;
	merg(0,n-1);
	for (int i = 0; i < n; i++)cout << vm[i] << ' ';
	cout << endl;

	vector<ll>bub(n);
	bub = v;
	bub = bubble(v);
	for (int i = 0; i < n; i++)cout << bub[i] << ' ';
	cout << endl;
	qu = vector<ll>(n);
	qu = v;
	quck(0,n-1);
	for (int i = 0; i < n; i++)cout << qu[i] << ' ';
	cout << endl;


	/********************/
	ll itm; cin >> itm;
	cout << bainry(v, itm) << endl;


	return 0;
}
