#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main() {
	fast;
	ll n;
	while (cin >> n && n) {
		ll res = 0, prv; priority_queue<ll>pq;
		for (int i = 0; i < n; i++) {
			int x; cin >> x; pq.push(-x);
		}
		while (pq.size()>1) {
			int sm = abs(pq.top()); pq.pop();
			sm += abs(pq.top());
			 pq.pop(); res+= sm;
			 pq.push(-sm);
		}
		cout << res << endl;
	}
	return 0;
}
