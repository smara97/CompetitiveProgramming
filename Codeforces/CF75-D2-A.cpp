#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
int main() {
  fast;
  ll x, y;
  cin >> x >> y;
  ll sum = x + y;
  string a,b; stringstream ss;
  ss << x; ss >> a;
  stringstream sss;
  sss << y; sss >> b;
  for (int i = 0; i < a.length(); i++) {
	  if (a[i] == '0')a.erase(i, 1), i--;
  }
  for (int i = 0; i < b.length(); i++) {
	  if (b[i] == '0')b.erase(i, 1), i--;
  }
  if (a.empty() || b.empty())cout << "NO" << endl;
  else {
	  stringstream sass,sas,saa,aas;
	  sas << a; sas >> x;
	  sass << b; sass >> y;
	  string c; saa << sum; saa >> c;
	  for (int i = 0; i < c.length(); i++) {
		  if (c[i] == '0')c.erase(i, 1), i--;
	  }
	  aas << c, aas >> sum;
	  if ((x + y) == sum)cout << "YES" << endl;
	  else cout << "NO" << endl;
  }

  return 0;
}
