#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.14159265;
typedef long long ll;
using namespace std;
vector<ll>v, tmp;
ll n,res;
void merge(int l1, int r1, int l2, int r2) {

	for (int i = l1; i <= r2; i++)
		tmp[i] = v[i];

	int ind = l1;
	while (l1 <= r1 && l2 <= r2) {
		
		if (tmp[l1] <= tmp[l2]) {
			v[ind++] = tmp[l1];
			l1++;
		}
		else {
			res += (r1 - l1+1);
			v[ind++] = tmp[l2];
			l2++;
		}
	}
	while (l1 <= r1) {
		v[ind++] = tmp[l1++];
	}
	while (l2 <= r2) {
		v[ind++] = tmp[l2++];
	}
}
void merge_sort(int l, int r) {

	if (l < r) {
		int mid = (l + r) / 2;
		 merge_sort(l, mid);
		 merge_sort(mid + 1, r);
		 merge(l, mid, mid+1 , r);
	}
}
int main()
{
	fast;
	while(cin>>n){
		if (!n)break;
		v = vector<ll>(n + 5);
		tmp = vector<ll>(n + 5);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		res = 0;
		merge_sort(0, n - 1);
		if (res % 2) 
			cout << "Marcelo" << endl;
		else cout << "Carlos" << endl;
	}
	return 0;
}
