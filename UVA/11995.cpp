#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
int main() {
	int num;
	while (cin >> num) {
		stack<int>st;
		queue<int>q;
		priority_queue<int>pq;
		int op2 = 0, s = 0, qq = 0, pqq = 0;
		for (int i = 0; i < num; i++) {
			int op, x;
			cin >> op >> x;
			if (op == 1) {
				st.push(x);
				q.push(x);
				pq.push(x);
			}
			else {
				op2++;
				if (st.size())
					if (st.top() == x)st.pop(), s++;
				if (pq.size())
					if (pq.top() == x)pq.pop(), pqq++;
				if (q.size())
					if (q.front() == x)q.pop(), qq++;
			}
		}
		if (qq!=op2 && s!=op2 && pqq!=op2)cout << "impossible" << endl;
		else {
			if (s==op2 && pqq!=op2 && qq!=op2)cout << "stack" << endl;
			else if (s != op2 && pqq != op2 && qq == op2)cout << "queue"<<endl;
			else if (s != op2 && pqq == op2 && qq != op2)cout << "priority queue" << endl;
			else cout << "not sure"<<endl;
		}
	}
	return 0;
}
