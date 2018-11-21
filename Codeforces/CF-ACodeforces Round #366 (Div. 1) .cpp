#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define m3lsh return 0;
typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int  dix[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int  diy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

int main() {
	fast;
	int n, q;
	cin >> n >> q;
	vector<set<int>>v(300099);
	set<pair<int, int>>opt;
	vector<bool>mark(300099, 0);
	int res = 0,i=1;
	while(q--) {
		int tp, num; cin >> tp >> num;
		if (tp == 1) {
			 opt.insert({ i,num });
			 v[num].insert(i); i++;
		}
		else if (tp == 2) {
			for (auto e : v[num])
				opt.erase({ e,num });
			v[num].clear();
		}
		else {
			while (opt.size()) {
				if (opt.begin()->first> num)break;
				int opnm = opt.begin()->first;
				int nm = opt.begin()->second;
				opt.erase(opt.begin());
				v[nm].erase(opnm);
			}
		}
		cout << opt.size() << endl;
	}

	m3lsh;
}
