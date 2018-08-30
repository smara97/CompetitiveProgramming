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
   int n;
   cin >> n;
   cin.ignore();
   string v[] = { "","2","3","223","5","35","7","7222","7233" };
   string s;
   cin >> s; string res = "";
   for (int i = 0; i < s.length(); i++) {
	   if(s[i]-'0'>0)
		res += v[s[i] - '0'-1];
   }
   sort(res.rbegin(), res.rend());
   cout << res << endl;
   return 0;
}
