#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
typedef long long ll;
int main()
{
	fast;
	int tc;
	cin >> tc;
	while (tc--) {
		int p; cin >> p;
		cin.ignore();
		int mn=INT_MAX; vector<int>pu;
		vector<vector<int>>ad(p + 1);
		for (int i = 1; i <= p; i++) {
			string x; 
			getline(cin, x);
				string tmp = "";
				for (int j = 0; j < x.length(); j++) {
					if (x[j] == ' ') {
						stringstream s;
						s << tmp; int  xx; s >> xx;
						if(xx!=i)ad[i].push_back(xx); tmp = "";
					}
					else tmp += x[j];
				}
				stringstream s;
				s << tmp; int  xx; s >> xx;
				if (xx != i)
					ad[i].push_back(xx);
		}
		for (int i = 1; i <= p; i++) {
			if (ad[i].size() < mn) {
				mn = ad[i].size();
				pu.clear(); pu.push_back(i);
			}
			else if (mn == ad[i].size()) {
				pu.push_back(i);
			}
		}
		for (int i = 0; i < pu.size()-1; i++)
			cout << pu[i] << ' ';
		cout <<pu.back()<< endl;
	}
	return 0;
}
