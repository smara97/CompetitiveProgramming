#define _CRT_SECURE_NO_WARINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<cmath>
#include<bitset>
#include<iterator>
#include<queue>
#include<unordered_map>
#include<iomanip>
#include<functional>
#include<stack>
#include<sstream>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;

int main(){
	int n;
	cin >> n;
	cin.ignore();
	map<string, string>mp;
	vector<vector<string>>vs(1e5);
	vector<bool>ty(1e5,0);
	int tr = 0, cat = 0;
	string thro = "";
	bool fin = 0;
	while (n--) {
		string s;
		getline(cin, s);
		for (int i = 0; i < s.length(); i++) {
			if (isalpha(s[i]))break;
			s.erase(i, 1), i--;
		}
		if (s.empty())continue;
		if (s[1] == 'a') {
			string temp = "",temp1="";
			for (int i = 0; i < s.length(); i++) {
				if (s[i] == '(') {
					int j = i + 1; 
					while (s[j] != ',') {
						if (s[j] != ' ')temp += s[j]; j++;
					}
					i = j;
				}
				if (s[i] == '"') {
					int j = i + 1; 
					while (s[j] != '"') {
						temp1 += s[j]; j++;
					}
					i = j;
					mp[temp] = temp1;
				}
			}
			if (ty[tr]) {
				if (temp == thro) {
					cout << temp1 << endl;
					return 0;
				}
				ty[tr] = 0;
			}
			tr -- ;
		}
		else if (s[1] == 'h') {
			string temp = "";
			for (int i = 0; i < s.length(); i++) {
				if (s[i] == '(') {
					int j = i + 1;
					while (j<s.length()&&s[j] != ')') {
						if (s[j] != ' ')temp += s[j];
						j++;
					}
					thro = temp;
					break;
				}

			}
			for (int i = 1; i <= tr; i++) {
				ty[i] = 1;
			}
		}
		else {
			tr++;
		}
		
	}
	cout << "Unhandled Exception" << endl;
	return 0;
}
