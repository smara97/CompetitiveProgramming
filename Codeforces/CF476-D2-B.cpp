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
int main() {
   fast;
   string s, ss;
   cin >> s >> ss;
   int sum = 0;
   for (int i = 0; i < s.length(); i++) {
	   sum += bool(s[i] == '+');
	   sum -= bool(s[i] == '-');
   }
   int sums = 0;
   for (int i = 0; i < ss.length(); i++) {
	   if (ss[i] != '?') {
		   if (ss[i] == '-')sums--;
		   else sums++;
	   }
   }
   double nm = count(ss.begin(), ss.end(), '?'), res = 0;
   for (ll i = 0; i < (1 <<(int) nm); i++) {
	   int pl = 0;
	   for (int j = 0; j < nm; j++) {
		   if (i&(1 << j))pl++;
		   else pl--;
	   }
	   if ((sums + pl) == sum)res++;
   }
   cout << fixed << setprecision(9) << (res / double(1<<(int)nm)) << endl;
   return 0;
}
