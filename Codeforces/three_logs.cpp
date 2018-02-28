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
char grid[305][305];
bool check(pair<int, int>A, pair<int, int>B, pair<int, int>C) {
	bool ok;
	int dif = B.second - A.second;
	if (dif == C.second&&A.first == C.first) {
		int r = A.first + B.first, c = B.second;
		if (r != c)return 0;
		ok = 1;
		for (int i = 0; i < A.first; i++)
			for (int j = A.second; j < B.second; j++)
				grid[i][j] = 'C';
		cout << A.first + B.first << endl;
		for (int i = 0; i < A.first + B.first; i++, cout << endl)
			for (int j = 0; j < B.second; j++)
				cout << grid[i][j];
		return 1;
	}
	else if (dif == C.first&&C.second == A.first) {
		swap(C.first, C.second);
		ok = 1;
		for (int i = 0; i < A.first; i++)
			for (int j = A.second; j < B.second; j++)
				grid[i][j] = 'C';
		int r = A.first + B.first, c = B.second;
		if (r != c)return 0;
		cout << A.first + B.first << endl;
		for (int i = 0; i < A.first + B.first; i++, cout << endl)
			for (int j = 0; j < B.second; j++)
				cout << grid[i][j];
		return 1;
	}
	return 0;
}
bool check1(pair<int, int>A, pair<int, int>B, pair<int, int>C) {
	bool ok = 0;
	int dif = A.second - B.second;
	if (dif == C.second&&B.first == C.first) {
		ok = 1;
		for (int i = A.first; i < (A.first + B.first); i++)
			for (int j = B.second; j < A.second; j++)
				grid[i][j] = 'C';
		int r = A.first + B.first, c = A.second;
		if (r != c)return 0;
		cout << A.first + B.first << endl;
		for (int i = 0; i < A.first + B.first; i++, cout << endl)
			for (int j = 0; j < A.second; j++)
				cout << grid[i][j];
		return 1;
	}
	else if (dif == C.first&&C.second == B.first) {
		swap(C.first, C.second);
		ok = 1;
		for (int i = A.first; i < B.first + A.first; i++)
			for (int j = B.second; j < A.second; j++)
				grid[i][j] = 'C';
		int r = A.first + B.first, c = A.second;
		if (r != c)return 0;
		cout << A.first + B.first << endl;
		for (int i = 0; i < A.first + B.first; i++, cout << endl)
			for (int j = 0; j < A.second; j++)
				cout << grid[i][j];
		return 1;
	}
	return 0;
}
int main(){
	pair<int, int>A, A1, B, B1, C, C1;
	vector<bool>tm(6, 0);
	cin >> A.first >> A.second;
	A1.second = A.first; A1.first = A.second;
	cin >> B.first >> B.second;
	B1.second = B.first; B1.first = B.second;
	cin >> C.first >> C.second;
	C1.second = C.first; C1.first = C.second;
	 bool ok = 0;
	int r = 0, c = 0;
	//A B
	for (int i = 0; i < A.first; i++)
		for (int j = 0; j < A.second; j++)
			grid[i][j] = 'A';
	r = A.first; c = A.second;
	for (int i = r; i < (r + B.first); i++)
		for (int j = 0; j < B.second; j++)
			grid[i][j] = 'B';
	
	if (A.second == B.second) {
		if (C.second == A.second) {
			for (int i = (A.first + B.first); i < ((A.first + B.first)+ C.first); i++)
				for (int j = 0; j < C.second; j++)
					grid[i][j] = 'C';
			r += C.first;
			if ((A.first + B.first + C.first) == A.second) {

				cout << (A.first + B.first + C.first) << endl;
				for (int i = 0; i < (A.first + B.first + C.first); i++, cout << endl)
					for (int j = 0; j < A.second; j++)
						cout << grid[i][j];
				return 0;
			}
		}
		else if (C.first == A.second) {
			for (int i = (A.first + B.first); i < ((A.first + B.first) + C.second); i++)
				for (int j = 0; j < C.first; j++)
					grid[i][j] = 'C';
			r += C.second;
			if ((A.first + B.first + C.second) == A.second) {
				cout << (A.first + B.first + C.second) << endl;
				for (int i = 0; i < (A.first + B.first + C.second); i++, cout << endl)
					for (int j = 0; j < A.second; j++)
						cout << grid[i][j];
				return 0;
			}
			
		}
		else {
			if ((A.first + B.first) == C.first) {
				if ((A.second + C.second) == (C.first)) {
					cout<<C.first<<endl;
					for (int i = 0; i < (A.first + B.first); i++, cout << endl) {
						for (int j = 0; j < A.second; j++)
							cout << grid[i][j];
						for (int j = A.second; j < (A.second + C.second); j++)
							cout << 'C';
					}
					return 0;
				}
			}
			else if ((A.first + B.first) == C.second) {
				if ((A.second + C.first) == (C.second)) {
					cout << C.second << endl;
					for (int i = 0; i < (A.first + B.first); i++, cout << endl) {
						for (int j = 0; j < A.second; j++)
							cout << grid[i][j];
						for (int j = A.second; j < (A.second + C.first); j++)
							cout << 'C';		
					}
					return 0;
				}
			}
		}
	}
	else {
		if (B.second > A.second) {
			ok = check({ A.first,A.second }, { B.first,B.second }, { C.first,C.second });
			if (ok)return 0;
		}
		else {
			ok= check1({ A.first,A.second }, { B.first,B.second }, { C.first,C.second });
			if (ok)return 0;
		}
	}
	r = 0, c = 0;
	//A1 B
	for (int i = 0; i < 304; i++)
		for (int j = 0; j < 304; j++)
			grid[i][j] = 0;
	for (int i = 0; i < A1.first; i++)
		for (int j = 0; j < A1.second; j++)
			grid[i][j] = 'A';
	r = A1.first, c = A1.second;
	for (int i = r; i < (r + B.first); i++)
		for (int j = 0; j < B.second; j++)
			grid[i][j] = 'B';
	r += B.first;
	if (A1.second == B.second) {
		if (C.second == A1.second) {
			for (int i = (A1.first + B.first); i < ((A1.first + B.first) + C.first); i++)
				for (int j = 0; j < C.second; j++)
					grid[i][j] = 'C';
			r += C.first;
			if (((A1.first + B.first) + C.first) == A1.second) {
				cout << (A1.first + B.first) + C.first << endl;
				for (int i = 0; i < (A1.first + B.first) + C.first; i++, cout << endl)
					for (int j = 0; j < A1.second; j++)
						cout << grid[i][j];
				return 0;
			}
		}
		else if (C.first == A1.second) {
			for (int i = (A1.first + B.first); i < ((A1.first + B.first) + C.second); i++)
				for (int j = 0; j < C.first; j++)
					grid[i][j] = 'C';
			r += C.second;
			if (((A1.first + B.first) + C.second) == A1.second) {
				cout << (A1.first + B.first) + C.second << endl;
				for (int i = 0; i < (A1.first + B.first) + C.second; i++, cout << endl)
					for (int j = 0; j < A1.second; j++)
						cout << grid[i][j];
				return 0;
			}
		}
		else {
			if ((A1.first + B.first) == C.first) {
				if ((A1.second + C.second) == (C.first)) {
					cout << C.first << endl;
					for (int i = 0; i < (A1.first + B.first); i++, cout << endl) {
						for (int j = 0; j < A1.second; j++)
							cout << grid[i][j];
						for (int j = A1.second; j < (A1.second + C.second); j++)
							cout << 'C';
					}
					return 0;
				}
			}
			else if ((A1.first + B.first) == C.second) {
				if ((A1.second + C.first) == (C.second)) {
					cout << C.second << endl;
					for (int i = 0; i < (A1.first + B.first); i++, cout << endl) {
						for (int j = 0; j < A1.second; j++)
							cout << grid[i][j];
						for (int j = A1.second; j < (A1.second + C.first); j++)
							cout << 'C';
					}
					return 0;
				}
			}
		}

	}
	else {
		if (B.second > A1.second) {
			ok = check({ A1.first,A1.second }, { B.first,B.second }, { C.first,C.second });
			if (ok)return 0;
		}
		else {
			ok = check1({ A1.first,A1.second }, { B.first,B.second }, { C.first,C.second });
			if (ok)return 0;
		}
	}
	r = 0, c = 0;
	//A1 B1
	for (int i = 0; i < 304; i++)
		for (int j = 0; j < 304; j++)
			grid[i][j] = 0;
	for (int i = 0; i < A1.first; i++)
		for (int j = 0; j < A1.second; j++)
			grid[i][j] = 'A';
	r = A1.first, c = A1.second;
	for (int i = r; i < (r + B1.first); i++)
		for (int j = 0; j < B1.second; j++)
			grid[i][j] = 'B';
	r += B1.first;
	if (A1.second == B1.second) {
		if (C.second == A1.second) {
			for (int i = (A1.first + B1.first); i < ((A1.first + B1.first) + C.first); i++)
				for (int j = 0; j < C.second; j++)
					grid[i][j] = 'C';
			r += C.first;
			if (((A1.first + B1.first) + C.first) == A1.second) {
				cout << (A1.first + B1.first) + C.first << endl;
				for (int i = 0; i < (A1.first + B1.first) + C.first; i++, cout << endl)
					for (int j = 0; j < A1.second; j++)
						cout << grid[i][j];
				return 0;
			}
		}
		else if (C.first == A1.second) {
			for (int i = (A1.first + B1.first); i < ((A1.first + B1.first) + C.second); i++)
				for (int j = 0; j < C.first; j++)
					grid[i][j] = 'C';
			r += C.second;
			if (((A1.first + B1.first) + C.second) ==A1.second ) {
				cout << (A1.first + B1.first) + C.second << endl;
				for (int i = 0; i < (A1.first + B1.first) + C.second; i++, cout << endl)
					for (int j = 0; j < A1.second; j++)
						cout << grid[i][j];
				return 0;
			}
		}
		else {
			if ((A1.first + B1.first) == C.first) {
				if ((A1.second + C.second) == (C.first)) {
					cout << C.first << endl;
					for (int i = 0; i < (A1.first + B1.first); i++, cout << endl) {
						for (int j = 0; j < A1.second; j++)
							cout << grid[i][j];
						for (int j = A1.second; j < (A1.second + C.second); j++)
							cout << 'C';
					}
					return 0;
				}
			}
			else if ((A1.first + B1.first) == C.second) {
				if ((A1.second + C.first) == (C.second)) {
					cout << C.second << endl;
					for (int i = 0; i < (A1.first + B1.first); i++, cout << endl) {
						for (int j = 0; j < A1.second; j++)
							cout << grid[i][j];
						for (int j = A1.second; j < (A1.second + C.first); j++)
							cout << 'C';
					}
					return 0;
				}
			}
		}
	}
	else {
		if (B1.second > A1.second) {
			ok = check({ A1.first,A1.second }, { B1.first,B1.second }, { C.first,C.second });
			if (ok)return 0;
		}
		else {
			ok = check1({ A1.first,A1.second }, { B1.first,B1.second }, { C.first,C.second });
			if (ok)return 0;
		}
	}
	r = 0, c = 0;
	//A B1
	for (int i = 0; i < 304; i++)
		for (int j = 0; j < 304; j++)
			grid[i][j] = 0;
	for (int i = 0; i < A.first; i++)
		for (int j = 0; j < A.second; j++)
			grid[i][j] = 'A';
	r = A.first;
	for (int i = r; i < (r + B1.first); i++)
		for (int j = 0; j < B1.second; j++)
			grid[i][j] = 'B';
	r += B1.first;
	if (A.second == B1.second) {
		if (C.second == A.second) {
			for (int i = (A.first + B1.first); i < ((A.first + B1.first) + C.first); i++)
				for (int j = 0; j < C.second; j++)
					grid[i][j] = 'C';
			r += C.first;
			if (((A.first + B1.first) + C.first) == A.second) {
				cout << (A.first + B1.first) + C.first << endl;
				for (int i = 0; i < (A.first + B1.first) + C.first; i++, cout << endl)
					for (int j = 0; j < A.second; j++)
						cout << grid[i][j];
				return 0;
			}
		}
		else if (C.first == A.second) {
			for (int i = (A.first + B1.first); i < ((A.first + B1.first) + C.second); i++)
				for (int j = 0; j < C.first; j++)
					grid[i][j] = 'C';
			r += C.second;
			if (((A.first + B1.first) + C.second) == A.second) {
				cout << (A.first + B1.first) + C.second << endl;
				for (int i = 0; i < (A.first + B1.first) + C.second; i++, cout << endl)
					for (int j = 0; j < A.second; j++)
						cout << grid[i][j];
				return 0;
			}
		}
		else {
			if ((A.first + B1.first) == C.first) {
				if ((A.second + C.second) == (C.first)) {
					cout << C.first << endl;
					for (int i = 0; i < (A.first + B1.first); i++, cout << endl) {
						for (int j = 0; j < A.second; j++)
							cout << grid[i][j];
						for (int j = A.second; j < (A.second + C.second); j++)
							cout << 'C';
					}
					return 0;
				}
			}
			else if ((A.first + B1.first) == C.second) {
				if ((A.second + C.first) == (C.second)) {
					cout << C.second << endl;
					for (int i = 0; i < (A.first + B1.first); i++, cout << endl) {
						for (int j = 0; j < A.second; j++)
							cout << grid[i][j];
						for (int j = A.second; j < (A.second + C.first); j++)
							cout << 'C';
					}
					return 0;
				}
			}
		}
	}
	else {
		if (B1.second > A.second) {
			ok = check({ A.first,A.second }, { B1.first,B1.second }, { C.first,C.second });
			if (ok)return 0;
		}
		else {
			ok = check1({ A.first,A.second }, { B1.first,B1.second }, { C.first,C.second });
			if (ok)return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
