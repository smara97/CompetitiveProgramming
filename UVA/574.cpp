#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main() {
	int n, t;
	while (cin >> n >> t) {
		if (!n && !t)break;
		cout << "Sums of " << n << ":" << endl;
		vector<ll>v(t), pu; bool ok = 0;
		set<vector<ll>>stv;
		for (int i = 0; i < t; i++)
			cin >> v[i];
		ll res = 0,sum=0;
		for (int i = 0; i < (1 << t); i++) {
			sum = 0; int pr = -1; pu.clear();
			for (int j = 0; j < t; j++) {
				if (i&(1 << j)) {
					sum += v[j];
					pu.push_back(v[j]);
				}
			}
			if (sum == n) {
				ok = 1;
				stv.insert(pu);
			}
		}
		if (!ok)cout << "NONE" << endl;
		else {
			set<vector<ll>>::iterator it = stv.end();
			it--;
			while (1) {
				vector<ll>pt = *it;
				for (int i = 0; i < pt.size(); i++) {
					if (i == pt.size() - 1)cout << pt[i] << endl;
					else cout << pt[i] << '+';
				}
				if (it == stv.begin())break;
				else it--;
			}
		}
	}
	return 0;
}
