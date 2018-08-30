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
ll mod(ll b, ll p, ll m) {
	if (p == 0)return 1;
	if (p % 2 == 0) {
		ll x = mod(b, p / 2, m);
		return (x*x) % m;
	}
	else return ((b%m)*mod(b, p - 1, m)) % m;
}
int main() {
   fast;
   ll b, p, m;
   while (cin >> b >> p >> m) {
	   cout << mod(b, p, m) << endl;
   }
   return 0;
}
