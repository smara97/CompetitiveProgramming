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
bool plan(string s) {
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - 1 - i])return 0;
	}
	return 1;
}
int main() {
	string s; vector<string>vs;
	while(getline(cin,s)){
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ') {
				string temp = ""; int j = i;
				while (j < s.length() && s[j] != ' ') {
					temp += s[j], j++;
				}
				i = j-1;
				reverse(temp.begin(), temp.end());
				cout << temp;
			}
			else cout << s[i];
		}
		cout << "\n";
	}
	return 0;
}
