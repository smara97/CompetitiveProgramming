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
   ll n, m, x;
   cin >> n >> m >> x;
   char ad[100][100];
   vector<pair<int, int>>vp;
   map<char, bool>mp;
   vector < vector<pair<int, int>>>adp(26);
   for (int i = 1; i <=n; i++) {
	   for (int j = 1; j <= m; j++) {
		   cin >> ad[i][j];
		   if (ad[i][j] == 'S')vp.push_back({ i ,j  });
		   else {
			   mp[ad[i][j]] = 1;
			   adp[ad[i][j] - 'a'].push_back({ i,j });
		   }
	   }
   }
   int y; cin >> y;
   cin.ignore();
   string s; cin >> s;
   int res = 0;
   map<char, int>memo;
   for (int i = 0; i < s.length(); i++) {
	   if (mp[s[i]])continue;
	   bool exis = 0;
	   if (!mp[char(s[i] + 32)] || vp.empty()) {
		   cout << -1 << endl; return 0;
	   }
	   s[i] = char(s[i] + 32); bool ok = 0;
	   if (memo[s[i]]!=0) {
		   res += bool(memo[s[i]]==2);
		   continue;
	   }
	   for (int j = 0; j < vp.size(); j++) {
		   for (int k = 0; k < adp[s[i] - 'a'].size(); k++) {
			   double xd = dis(vp[j].first, adp[s[i] - 'a'][k].first, vp[j].second, adp[s[i] - 'a'][k].second);
			   if (xd <= x) {
				   ok = 1; break;
			   }
		   }
		   if (ok)break;
	   }
	   if (ok)memo[s[i]] = 1;
	   else memo[s[i]] = 2;
	   res += bool(!ok);
   }
   cout << res << endl;
   return 0;
}
