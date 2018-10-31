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

int main()
{
	fast;
	int n;
	cin >> n;
	vector<int>va(n), vb(n), vc(n); set<int>st;
	for (int i = 0; i < n; i++)va[i] = i;
	for (int i = 0; i < n - 1; i++)vb[i] = i + 1; vb[n - 1] = 0;
	for (int i = 0; i < n; i++)vc[i] = (va[i] + vb[i]) % n,st.insert(vc[i]);
	if (st.size() != n)cout << -1 << endl;
	else {
		for (int i = 0; i < n; i++)cout << va[i] << ' '; cout << endl;
		for (int i = 0; i < n; i++)cout << vb[i] << ' '; cout << endl;
		for (int i = 0; i < n; i++)cout << vc[i] << ' '; cout << endl;

	}
	m3lsh;
}
