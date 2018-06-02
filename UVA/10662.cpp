#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
using namespace std;
typedef long long ll;
int main()
{
	fast;
	int t, r, h;
	while (cin>>t>>r>>h) {
		vector<int>v(1001), v2(1001), v3(1001);
		int ad[100][100], ad2[100][100], ad3[100][100];
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < r + 1; j++) {
				if (!j)cin >> v[i];
				else cin >> ad[i][j-1];
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < h + 1; j++) {
				if (!j)cin >> v2[i];
				else cin >> ad2[i][j-1];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < t + 1; j++) {
				if (!j)cin >> v3[i];
				else cin >> ad3[i][j-1];
			}
		}
		int x = 0, y = 0, z = 0,res=INT_MAX;
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < r; j++) {
				if (!ad[i][j]) {
					for (int k = 0; k < h; k++) {
						if (!ad2[j][k]) {
							if (!ad3[k][i]) {
								if (res > (v[i] + v2[j] + v3[k])) {
									x = i , y = j , z = k ;
									res = v[i] + v2[j] + v3[k];
								}
							}
						}
					}
				}
			}
		}
		if (res!=INT_MAX)cout << x << ' ' << y << ' ' << z << ':' << res << endl;
		else cout << "Don't get married!" << endl;
	}
	return 0;
} 
