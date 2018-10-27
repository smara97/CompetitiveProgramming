#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define m3lsh return 0;
typedef long long ll;
typedef unsigned long long ull;


ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int  dix[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int  diy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
ll sp[100001][30], lft[100001], rgt[100001], tmp[100001];
int n, q;
void build() {
	int cnt = 1,prv=tmp[0];
	for (int i = 1; i < n-1; i++) {
		if (tmp[i] == prv)cnt++;
		else {
			for (int j = i - 1; j >= 0; j--) {
				if (prv != tmp[j])break;
				sp[j][0] = cnt;
			}
			cnt = 1; prv = tmp[i];
		}
	}
	for (int j = n - 1; j >= 0; j--) {
		if (prv != tmp[j])break;
		sp[j][0] = cnt;
	}
	lft[0] = 0, rgt[n - 1] = n - 1;
	for (int i = 1; i < n; i++) {
		if (tmp[i] == tmp[i - 1])lft[i] = lft[i - 1];
		else lft[i] = i;
	}
	for (int i = n - 2; i >= 0; i--) {
		if (tmp[i] == tmp[i + 1])rgt[i] = rgt[i + 1];
		else rgt[i] = i;
	}
	for (int j = 1; j <= log2(n); j++) {
		for (int i = 0; i + (1 << j) - 1 < n; i++) {
			sp[i][j] = max(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int res(int u, int v) {
	int ni, nj, k, Ans = 0;
	ni = rgt[u] + 1, nj =lft[v] - 1;
	if (ni <= nj) {
		k = log2(nj - ni + 1);
		Ans = max(sp[ni][k], sp[nj - (1 << k) + 1][k]);
		Ans = max(max(Ans, (ni - 1) - u + 1), v - (nj + 1) + 1);
	}
	else {
		if (tmp[u] != tmp[v])
			Ans = max(ni - u, v - nj);
		else
			Ans = v - u + 1;
	}

	return Ans;

}
int main()
{
	fast;
	while (cin >> n) {
		if (!n)break; cin >> q;
		for (int i = 0; i < n; i++)cin >> tmp[i];
		build();
		for (int i = 0; i < q; i++) {
			int u, v; cin >> u >> v;
			cout << res(u - 1, v - 1) << endl;
		}
	}
	m3lsh;
}
