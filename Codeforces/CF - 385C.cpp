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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
vector<ll>primes(2*1e7,0); 
vector<ll>cnt(2 * 1e7,0);
bitset< 20000000 + 1>bt;
void seve(ll num) {
	bt.set();
	bt[0] = bt[1] = 0;
	for (ll i = 2; i <= num; i++) {
		if (bt[i]) {
			primes[i] += cnt[i];
			for (ll j = i+i; j <= num; j += i)bt[j] = 0,primes[i]+=cnt[j];
		}
	}
}
int main() {
   fast;
   int n; cin >> n;
   vector<ll>v(n);
   for (int i = 0; i < n; i++)cin >> v[i],cnt[v[i]]++;
   seve((ll)2*1e7);
   for (int i = 1; i < (ll)2 * 1e7; i++)primes[i] += primes[i - 1];
   int m; cin >> m;
   while (m--) {
	   ll l, r;
	   cin >> l >> r;
	   l = min(l, (ll)1e7), r = min(r, (ll)1e7);
	    cout << primes[r] - primes[l - 1] << endl;
   }
	return 0;
}
