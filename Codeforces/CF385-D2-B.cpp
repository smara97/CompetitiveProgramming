#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
void File() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}
int main() {
   fast;
   string s;
   cin >> s;
   vector<int>v;
   ll res = 0;
   for (int i = 0; i < (int)s.length() - 3; i++) {
	   bool ok = 0;
	   for (int j = i; j < (int)s.length() - 3; j++) {
		   string tmp = s.substr(j, 4);
		   if (tmp == "bear") {
			   res += (s.length() - (j + 3));
			   break;
		   }
	   }
   }
  
   cout << res << endl;
   return 0;
}
