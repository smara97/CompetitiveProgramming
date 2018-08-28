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
int main() {
   fast;
   ll a, b;
   cin >> a >> b;
   int res = 0;
   int lf = 0, ri = 0;
   while (a % 2 == 0)lf++, a /= 2;
   while (b % 2 == 0)ri++, b /= 2;
   res += abs(ri - lf);
   lf = ri = 0;
   while (a % 3 == 0)lf++, a /=3;
   while (b % 3 == 0)ri++, b /=3;
   res += abs(ri - lf);
   lf = ri = 0;
   while (a % 5 == 0)lf++, a /=5;
   while (b % 5 == 0)ri++, b /=5;
   res += abs(ri - lf);
   if(a!=b)
	cout <<  -1 << endl;
   else cout << res << endl;
   return 0;
}
