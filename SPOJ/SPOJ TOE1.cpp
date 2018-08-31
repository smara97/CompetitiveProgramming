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
bool win(string s) {
	set<char>r, d, c;
	r.insert(s[0]); r.insert(s[1]); r.insert(s[2]);
	if(r.size()==1 && * r.begin() != '.')return 1; r.clear();
	r.insert(s[5]); r.insert(s[4]); r.insert(s[3]);
	if (r.size() == 1 && * r.begin() != '.')return 1; r.clear();
	r.insert(s[6]); r.insert(s[7]); r.insert(s[8]);
	if (r.size() == 1 && * r.begin() != '.')return 1; r.clear();
	r.insert(s[0]); r.insert(s[4]); r.insert(s[8]);
	if (r.size() == 1 && * r.begin() != '.')return 1; r.clear();
	r.insert(s[2]); r.insert(s[4]); r.insert(s[6]);
	if (r.size() == 1 && * r.begin() != '.')return 1; r.clear();

	r.insert(s[0]); r.insert(s[3]); r.insert(s[6]);
	if (r.size() == 1 && *r.begin()!='.')return 1; r.clear();
	r.insert(s[1]); r.insert(s[4]); r.insert(s[7]);
	if (r.size() == 1 &&* r.begin() != '.')return 1; r.clear();
	r.insert(s[2]); r.insert(s[5]); r.insert(s[8]);
	if (r.size() == 1 && * r.begin() != '.')return 1; r.clear();
	return 0;

}
bool valid(string s) {
	bool ok = 0;
	string cur = ".........";
	queue<pair<string, bool>>pq;
	pq.push({cur, 1});
	while (pq.size()) {
		string sp = pq.front().first;
		bool pl = pq.front().second;
		pq.pop();
		if (s == sp)return 1;
		if (win(sp))continue;
		for (int i = 0; i < 9; i++) {
			if (sp[i] == '.') {
				if (pl)sp[i] = 'X';
				else sp[i] = 'O';
				if (sp[i] == s[i])pq.push({ sp,1 - pl });
				sp[i] = '.';
			}
		}
	}
	return 0;
}
int main() {
   fast;
   int tc;
   cin >> tc;
   while (tc--) {
	   string s = "";
	   for (int i = 0; i < 3; i++) {
		   string ss; cin >> ss;
		   s += ss;
	   }
	   if (valid(s))cout << "yes" << endl;
	   else cout << "no" << endl;
   }
   return 0;
}
