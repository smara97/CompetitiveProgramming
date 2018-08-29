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
double dis(int x, int xx, int y, int yy) {
	return double(sqrt(pow(x - xx, 2) + pow(y - yy, 2)));
}
bool ok(int i, int j, int n, int m) {
	return (i >= 0 && i < n&&j >= 0 && j < m);
}
int main() {
   fast;
   int n, m; char x;
   cin >> n >> m >> x;
   char ad[100][100];
   for (int i = 0; i < n; i++)
	   for (int j = 0; j < m; j++)
		   cin >> ad[i][j];
   set<char>st;
   for (int i = 0; i < n; i++) {
	   for (int j = 0; j < m; j++) {
		   if (ad[i][j] == x) {
			   if (ok(i - 1, j, n, m))
				   if (isalpha(ad[i - 1][j]))st.insert(ad[i - 1][j]);
			   if (ok(i + 1, j, n, m))
				   if (isalpha(ad[i + 1][j]))st.insert(ad[i + 1][j]);
			   if (ok(i , j-1, n, m))
				   if (isalpha(ad[i][j-1]))st.insert(ad[i][j-1]);
			   if (ok(i, j+1, n, m))
				   if (isalpha(ad[i][j+1]))st.insert(ad[i][j+1]);
		   }
	   }
   }
   if (binary_search(st.begin(), st.end(), x))cout << st.size() - 1 << endl;
   else cout << st.size() << endl;
   return 0;
}
