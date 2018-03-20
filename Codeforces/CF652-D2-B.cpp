#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>v(n+1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 2; i <= n; i++) {
		if (i % 2) {
			if (v[i] > v[i - 1]) {
				bool ok = 0;
				for (int j = 1; j < i; j++) {
					if (j % 2) {
						if (v[i] <= v[j - 1] && v[j] <= v[i - 1]) {
							ok = 1; swap(v[i], v[j]); break;
						}
					}
					else {
						if (v[i] >= v[j - 1] && v[j] <= v[i - 1]) {
							ok = 1; swap(v[i], v[j]); break;
						}
					}
				}
				if (!ok) {
					cout << "Impossible" << endl; return 0;
				}
			}
		}
		else {
			if (v[i] < v[i - 1]) {
				bool ok = 0;
				for (int j = 1; j < i; j++) {
					if (j % 2) {
						if (v[i] <= v[j - 1] && v[j] >= v[i - 1]) {
							ok = 1; swap(v[i], v[j]); break;
						}
					}
					else {
						if (v[i] >= v[j - 1] && v[j] >= v[i - 1]) {
							ok = 1; swap(v[i], v[j]); break;
						}
					}
				}
				if (!ok) {
					cout << "Impossible" << endl; return 0;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << v[i] << ' ';
	cout << endl;
	return 0;
}
