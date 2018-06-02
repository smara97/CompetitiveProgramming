#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
vector<ll>luc;
bool ok(ll num) {
	int f = 0, sv = 0;
	while (num) {
		f += bool(num % 10 == 4);
		sv += bool(num % 10 == 7);
		num /= 10;
	}
	return (f == sv);
}
void luck(ll num) {
	if (num > 1e9)return;
	num *= 10;
	if(ok(num+4))
		luc.push_back(num+4);
	luck(num + 4);
	if(ok(num+7))
		luc.push_back(num+7);
	luck(num + 7);
}
int main()
{
	fast;
	ll n;
	cin >> n;
	luck(0);
	sort(luc.begin(), luc.end());
	ll b = 0, en = luc.size() - 1, ind = 0;
	while (b <= en) {
		ll mid = (b + en) / 2;
		if (luc[mid] == n) {
			cout << n << endl;
			return 0;
		}
		else if (luc[mid] > n)ind = luc[mid], en = mid - 1;
		else b = mid + 1;
	}
	cout << ind << endl;
	return 0;
} 
