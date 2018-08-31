#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
void File() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
bool valid(int i, int j, int n, int m) {
	return (i >= 0 && i < n && j >= 0 && j < m);
}
int main() {
   fast;
   int n, m; int cnt = 0;
   while (cin >> n >> m) {
	   if (cnt)cout << endl;
	   cnt++;
	   vector<vector<int>>v(n, vector<int>(n));
	   for (int i = 0; i < n; i++)
		   for (int j = 0; j < n; j++)
			   cin >> v[i][j];
	   reverse(v.begin(), v.end());
	   for (int i = 0; i < n; i++)
		   for (int j = 1; j < n; j++)
			   v[i][j] += v[i][j - 1];
	   for (int i = 0; i < n; i++)
		   for (int j = 1; j < n; j++)
			   v[j][i] += v[j - 1][i];
	   int mm = n - m + 1;
	   m--;
	   ll sum = 0;
	   vector<vector<ll>>pu(mm,vector<ll>(mm));
	   for (int i = 0; i < mm; i++) {
		   for (int j = 0; j < mm; j++) {
			   ll d = v[i + m][j + m], a = 0, b = 0, c = 0;
			   if (valid(i - 1, j + m, n, n))b = v[i - 1][j + m];
			   if (valid(i + m, j - 1, n, n))c = v[i + m][j - 1];
			   if (valid(i - 1, j - 1, n, n))a = v[i - 1][j - 1];
			   pu[i][j] = d - b - c + a;
			    sum += d - b - c + a;
		   }
	   }
	   reverse(pu.begin(), pu.end());
	   for (int i = 0; i < mm; i++)
		   for (int j = 0; j < mm; j++)
			   cout << pu[i][j] << endl;
		   cout << sum << endl;
   }
   return 0;
}
