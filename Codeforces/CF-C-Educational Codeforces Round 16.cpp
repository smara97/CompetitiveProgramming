#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define m3lsh return 0;
typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int  dix[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int  diy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
ll memo[3000][3000],cur, odd,n;
void solve() {
	int colf = 1, cols = n, ii = n, colff = 1, colss = n;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;

		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}
	colf = 2, cols = n - 1, ii = n, colff = 2, colss = n - 1;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;
		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}
	colf = 3, cols = n - 2, ii = n, colff = 3, colss = n - 2;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;
		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}
	colf = 4, cols = n - 3, ii = n, colff = 4, colss = n - 3;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;
		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}
	colf = 5, cols = n - 4, ii = n, colff = 5, colss = n - 4;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;
		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}
	colf = 6, cols = n - 5, ii = n, colff = 6, colss = n - 5;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;
		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}
	colf = 7, cols = n - 6, ii = n, colff = 7, colss = n - 6;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;
		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}
	colf = 8, cols = n - 7, ii = n, colff = 8, colss = n - 7;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;
		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}
	colf = 9, cols = n - 8, ii = n, colff = 9, colss = n - 8;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;
		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}
	colf = 10, cols = n - 9, ii = n, colff = 10, colss = n - 9;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;
		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}
	colf = 11, cols = n - 10, ii = n, colff = 11, colss = n - 10;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;
		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}
	colf = 12, cols = n - 11, ii = n, colff = 12, colss = n - 11;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;
		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}
	colf = 13, cols = n - 12, ii = n, colff = 13, colss = n - 12;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;
		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}
	colf = 14, cols = n - 13, ii = n, colff = 14, colss = n - 13;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;
		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}
	colf = 15, cols = n - 14, ii = n, colff = 15, colss = n - 14;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;
		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}
	colf = 16, cols = n - 15, ii = n, colff = 16, colss = n - 15;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;
		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}
	colf = 17, cols = n - 16, ii = n, colff = 17, colss = n - 16;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;
		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}
	colf = 18, cols = n - 17, ii = n, colff = 18, colss = n - 17;
	for (int i = 1; i <= (n / 2) && odd; i++) {
		if (memo[i][colf] != -1 || memo[i][cols] != -1 ||
			memo[ii][colff] != -1 || memo[ii][colss] != -1)break;
		memo[i][colf] = cur; cur += 2;
		memo[i][cols] = cur; cur += 2;
		memo[ii][colff] = cur; cur += 2;
		memo[ii][colss] = cur; cur += 2;
		odd -= 4; colf++; cols--;
		ii--; colss--, colff++;
	}

}
int main() {
	fast;
	memset(memo, -1, sizeof memo);
	cin >> n;
	 odd = ((n*n) + 1) / 2; cur = 1;
	for (int i = 1; i <= n; i++)
		memo[(n / 2) + 1][i] = cur, cur += 2,odd--;

	for (int i = 1; i <= n; i++)
		if(memo[i][(n/2)+1]==-1)
			memo[i][(n/2)+1] = cur, cur += 2,odd--;
	while (odd) {
		solve();
	}
	cur = 2;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (memo[i][j] == -1)
				memo[i][j] = cur, cur += 2;
	for (int i = 1; i <= n; i++,cout<<endl)
		for (int j = 1; j <= n; j++)
			cout << memo[i][j] << ' ';
	m3lsh;
}
