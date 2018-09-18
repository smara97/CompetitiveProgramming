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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

int main() {
    fast;
    int n,m;
    cin>>n>>m;
    ll grid[100][100];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>grid[i][j];
    ll mxsum=0;
    for(int i=0; i<m; i++) {
        ll kad[100];
        for(int ii=0; ii<n; ii++)
            kad[ii]=0;

        for(int j=i; j<m; j++) {
            for(int jj=0; jj<n; jj++) {
                kad[jj]+=grid[jj][j];
            }
            ll cursum=0;
            for(int k=0; k<n; k++) {
                cursum=max(kad[k],cursum+kad[k]);
            }
            mxsum=max(cursum,mxsum);
        }

    }
    cout<<mxsum<<endl;
    return 0;

}
