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
   int n;
   cin >> n;
   set<ll>st;
   for (int i = 0; i < n; i++) {
	   ll x; cin >> x;
	   st.insert(x);
   }
   if (st.size() <= 3) {
	   if (st.size() <= 2)cout << "YES" << endl;
	   else {
		   set<ll>::iterator it = st.begin(), itt = it, i3t = it;
		   itt++, i3t++; i3t++;
		   if (abs(*it-*itt)==abs(*itt-*i3t))
			   cout << "YES" << endl;
		   else cout << "NO" << endl;
	   }
   }
   else cout << "NO" << endl;
   return 0;
}
