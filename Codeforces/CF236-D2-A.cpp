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
		string s, ss;
		cin >> s >> ss;
		for (int i = 0; i < s.length(); i++)
			if (s[i] < 97)s[i] = char(s[i] + 32);

		for (int i = 0; i < ss.length(); i++)
			if (ss[i] < 97)ss[i] = char(ss[i] + 32);
		if (s < ss)cout << -1 << endl;
		else if (s == ss)cout << 0 << endl;
		else cout << 1 << endl;
		return 0;
	}
