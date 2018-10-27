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
double dis(int i, int j, int ii, int jj) {
	return sqrt(pow(i - ii, 2) + pow(j - jj, 2));
}
int n, val[10001],k,ok=0;
ll memo[10001][1001];
bool solve(int in, ll sum) {
	if (in == n ) {
		if (sum == 0)return 1;
		return 0;
	}
	ll &ret = memo[in][sum];
	if (ret != -1)return memo[in][sum];
	ret = 0;
	ret=solve(in + 1, ((sum + val[in]) % k + k) % k );
	ret|=solve(in + 1, ((sum - val[in]) % k + k) % k);
	return ret;
}
int main()
{
	fast;
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)cin >> val[i]; ok = 0;
		memset(memo, -1, sizeof memo);
		if(n==1){
			if (val[0] % k == 0)ok = 1;
			else ok = 0;
		}
		ok= solve(1, ((val[0]%k)+k)%k);
		if (ok)cout << "Divisible" << endl;
		else cout << "Not divisible" << endl;	
	}
	m3lsh;
}
