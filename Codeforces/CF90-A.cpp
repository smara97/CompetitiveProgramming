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
double dis(int x, int y, int xx, int yy) {
	return double(sqrt(pow(x - xx, 2) + pow(y - yy, 2)));
}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
bitset<100000>bt;
vector<ll>prim;
void seve(ll num) {
	bt.set();
	bt[0] = bt[1] = 0;
	for (int i = 2; i <= num; i++) {
		if (bt[i]) {
			prim.push_back(i);
			for (int j = i + i; j <= num; j += i)bt[j] = 0;
		}
	}
}
int main() {
	fast;
	seve(1e4);
	string s;
	cin >> s; 
	map<char, int>mp; string res(4000, '0');
	vector<bool>tk(1e4, 0);
	for (int i = 0; i < s.length(); i++)mp[s[i]]++;
	for (int i = 1; i <= s.length(); i++) {
		if (bt[i]) {
			int cnt = 0,let=0; bool ok = 0; char x = ' ',resch=' ';
			for (int j = i; j <= s.length(); j += i) {
				if (!tk[j])cnt++;
				else {
					if (resch != res[j])resch = res[j], let++;
				}
			}
			for (auto it : mp) {
				if (it.second >= cnt ) {
					if (let == 0) {
						ok = 1; x = it.first;
						mp[it.first] -= cnt; break;
					}
					else if (let == 1 && resch == it.first) {
						ok = 1; x = it.first;
						mp[it.first] -= cnt; break;
					}
				}
			}
			if (ok) {
				for (int j = i; j <= s.length(); j += i)
					if(!tk[j])res[j] = x, tk[j] = 1;
			}
			else {
				cout << "NO" << endl; return 0;
			}
		}
	}
	cout << "YES" << endl;
	for (int i = 1; i <= s.length(); i++) {
		if (res[i] == '0') {
			for (auto it : mp) {
				if (it.second) {
					res[i]=it.first; mp[it.first]--; break;
				}
			}
		}
	}
	cout << res.substr(1, s.length()) << endl;
	return 0;;

}
