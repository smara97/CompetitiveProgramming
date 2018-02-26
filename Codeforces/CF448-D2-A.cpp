#define _CRT_SECURE_NO_WARINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<cmath>
#include<bitset>
#include<iterator>
#include<queue>
#include<unordered_map>
#include<iomanip>
#include<functional>
#include<stack>
#include<sstream>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int main() {
	fast;
	ll me = 0, cu = 0,n;
	for (int i = 0; i < 3; i++) {
		int x;
		cin >> x;
		cu += x;
	}
	for (int i = 0; i < 3; i++) {
		int x; cin >> x;
		me += x;
	}
	cin >> n;
	int cup=cu / 5; 
	cup += bool(cu % 5);
	int med=me / 10;
	med += bool(me % 10);
	if((med+cup)<=n)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;

}
