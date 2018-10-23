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
int wt[200], memo[200][200];
bool ok = 0;
void solve(int ind,int n,int sum,int sum2) {
	if (ind == n)return;
	if (sum && sum * 2 == sum2)ok = 1;
	solve(ind + 1, n, sum + wt[ind],sum2);
	solve(ind + 1, n, sum,sum2);
}
int main()
{
	fast;
	int test, el, i, sum;
	string s;
	stringstream ss;
	cin >> test; getline(cin, s);
	while (test--) {
		getline(cin, s);
		ss.clear();
		ss << s;
		i = 0;
		sum = 0;
		while (ss >> el) {
			wt[i++] = el;
			sum += el;
		}
		if (sum % 2)cout << "NO" << endl;
		else {
			ok = 0;
			solve(0, i, 0, sum);
			if (ok)cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	m3lsh;
}
