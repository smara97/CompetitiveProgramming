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
bool plan(string s) {
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - 1 - i])return 0;
	}
	return 1;
}
int main() {
	ll n;
	while(cin >> n) {
		if (!n)return 0;
		queue<ll>q; vector<ll>pu;
		for (int i = 1; i <= n; i++)
			q.push(i);
		while (q.size() != 1) {
			pu.push_back(q.front()); q.pop();
			q.push(q.front()); q.pop();
		}
		if(n==1)
			cout << "Discarded cards:";
		else cout << "Discarded cards: ";
		for (int i = 0; i < pu.size(); i++) {
			if (pu[i] == pu.back()) cout << pu[i];
			else cout << pu[i] << ", ";
		}
		cout << "\nRemaining card: " << q.front() << "\n";

	}
	return 0;
}
