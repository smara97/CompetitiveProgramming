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
   while (cin >> a >> b) {
	   if (!a && !b)break;
	   if (a < b)swap(a, b);
	   int cnt = 0;
	   while (a>0 && b>0) {
		   cnt++;
		   if (a / b > 1) break;
		   a -= b;
		   if (a < b)swap(a, b); 
	   }
	   if (cnt&1)cout << "Stan wins" << endl;
	   else cout << "Ollie wins" << endl;
   }
   return 0;
}
