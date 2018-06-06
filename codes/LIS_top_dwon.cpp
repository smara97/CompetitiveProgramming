#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
vector<ll>lis;
int memo[1000][1000];
ll solve(ll prv,int ind,int n) {
	if (memo[ind][n - ind] != -1)return memo[ind][n - ind];
	ll ans = 1;
	for (int i = ind + 1; i < n; i++) {
		if (lis[i] > prv)
			ans = max(ans, solve(lis[i], i, n) + 1);
	}
	return memo[ind][n - ind] = ans;
}
int main() {
  fast;
  int n;
  cin >> n;
  lis = vector<ll>(n);
  memset(memo, -1, sizeof memo);
  for (int i = 0; i < n; i++)cin >> lis[i];
  cout << solve(lis[0], 0, n) << endl;
	return 0;
}
