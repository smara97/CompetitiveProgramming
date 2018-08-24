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
   int n; cin >> n;
   cin.ignore();
   string s,temp="";
   cin >> s;
   for (int i = 0; i < n; i++)temp += '0';
   for (int i = 0; i < s.length(); i++) {
	   int num = (n - i) / 2 -bool((n-i)%2==0),ind=-1;
	   while (num>=0) {
		   ind++;
		   if (temp[ind] == '0')num--;
	   }
	   temp[ind] = s[i];
   }
   cout << temp << endl;
		return 0;
}
