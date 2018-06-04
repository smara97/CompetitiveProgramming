#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
vector<ll>w, v;
ll n, s;
ll memo[1010][40];
ll solve(ll rem,ll ind) {
	if (memo[ind][rem] != -1)return memo[ind][rem];
	ll ans = 0;
	for (int i = ind; i<n; i++) {
		if (w[i] <= rem)ans = max(ans, solve(rem - w[i], i + 1) + v[i]);
	}
	return memo[ind][rem] = ans;
}
int main() {
  fast;
  int tc;
  cin >> tc;
  while (tc--) {
	  cin >> n;
	  w = v = vector<ll>(n);
	  memset(memo, -1, sizeof memo);
	  for (int i = 0; i < n; i++)cin >> v[i] >> w[i];
	  ll s = 0; int x; cin >> x;
	  for (int i = 0; i < x; i++) {
		  int xx; cin >> xx;
		  s += solve(xx, 0);
	  }
	  cout << s << endl;
  }
	return 0;
}
