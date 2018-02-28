#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
#include <fstream>
#include <iomanip>
using namespace std;
int arr[1000];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL), cout.tie(NULL);
	string s; int c = 0; bool a = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		a = 0;
		for (int j = 0; j < i; j++)
		{
			if (s.at(i) == s.at(j))
			{
				a = 1; break;
			}
		}
		if (a == 0)
			c++;
	}
	if (c % 2 == 0)
		cout << "CHAT WITH HER!" << endl;
	else
		cout << "IGNORE HIM!" << endl;
			return 0;
}
