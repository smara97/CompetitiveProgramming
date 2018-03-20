#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main() {
	int n, t;
	while (cin >> n >> t) {
		vector<int>v(t),pu,clc;
		for (int i = 0; i < t; i++)
			cin >> v[i];
		ll res = 0,sum=0;
		for (int i = 0; i < (1 << t); i++) {
			sum = 0; int pr = -1; clc.clear();
			for (int j = 0; j < t; j++) {
				if (i&(1 << j)) {
					sum += v[j];
					clc.push_back(j);
				}
			}
			if (sum <= n) {
				if (sum > res) {
					res = sum; pu.clear();
					pu = clc; clc.clear();
				}
				else if (sum == res) {
					if (clc.size() > pu.size()) {

						res = sum; pu.clear();
						pu = clc; clc.clear();
					}
				}
			}
		}
		for (int i = 0; i < pu.size(); i++)
			cout << v[pu[i]] << ' ';
		cout << "sum:"<<res << endl;
	}
	return 0;
}
