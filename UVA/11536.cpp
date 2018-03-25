#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main()
{
	fast;
	int n, m, k; int tc = 1,t;
	cin >> t;
	for (int j = 0; j < t;j++) {
		cin >> n >> m >> k;
		vector<int>v(n+2);
		for (int i = 0; i < n; i++) {
			if (i > 2) {
				v[i] = (v[i - 1] + v[i - 2] + v[i - 3]) % m;
				v[i]++;
			}
			else v[i] = i + 1;
		}
		int p1 = 0, p2 = 0, cn = 0;
		int res = INT_MAX;
		set<int>st; vector<int>nu(1e6,0);
		while (p2 <= n) {
			if (st.size() == k) {
				res = min(p2 - p1 , res);
				if (v[p1] <= k) {
					nu[v[p1]]--;
					if (nu[v[p1]] <= 0)st.erase(v[p1]);
				}
				p1++;
			}
			else {
				if (v[p2] <= k) {
					st.insert(v[p2]);
					nu[v[p2]]++; 
				}
				p2++;
			}
		}

		if (res != INT_MAX) {
			cout << "Case " << tc++ << ": " << res << endl;
		}
		else cout << "Case "<<tc++ <<": sequence nai" << endl;
	}
	return 0;
}
