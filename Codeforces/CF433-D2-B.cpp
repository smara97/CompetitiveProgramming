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
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
int main()
{
	fast;
	ll n, m;
	cin >> n;
	vector<ll>tp1,tp2,stone(n);
	tp1.push_back(0); tp2.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> stone[i];
		tp1.push_back(tp1.back() + stone[i]);
	}
	sort(stone.begin(), stone.end());
	for (int i = 0; i < n; i++) {
		 tp2.push_back(tp2.back() + stone[i]);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b,t;
		cin >> t >> a >> b;
		if (t == 1) 
			cout << tp1[max(a, b)] - tp1[min(a, b)-1] << endl;
		else cout << tp2[max(a, b)]-tp2[min(a,b)-1]<< endl;
	}
	return 0;
}
