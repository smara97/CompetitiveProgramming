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
	typedef long long ll;
	using namespace std;
	int main(){
		ll x,ans=0; cin >> x;
		do {
			ll op = 1; ans++;
			while (op <= x)op <<= 1;
			x -= (op >> 1);
		} while (x>0);
		cout << ans << endl;
		return 0;
	}
