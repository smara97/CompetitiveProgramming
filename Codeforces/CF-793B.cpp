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
char grid[1200][1200];
bool vis[1200][1200][4][10];
int n,m;
bool valid(int r,int c) {
    return (r<n && r>=0 && c>=0 && c<m);
}
bool solve(int r,int c,int turn,int prv) {
    if(turn >2)return 0;
    if(!valid(r,c) || vis[r][c][turn][prv] ||grid[r][c]=='*' )return 0;
    if(grid[r][c]=='T')return 1;
    bool ans=0;
    vis[r][c][turn][prv]=1;
    if(prv==-1) {
        ans|=solve(r,c+1,turn ,0);
        ans|=solve(r,c-1,turn ,1);
        ans|=solve(r+1,c,turn ,2);
        ans|=solve(r-1,c,turn,3);
    } else {
        ans|=solve(r,c+1,turn +bool(prv!=0),0);
        ans|=solve(r,c-1,turn +bool(prv!=1),1);
        ans|=solve(r+1,c,turn +bool(prv!=2),2);
        ans|=solve(r-1,c,turn+bool(prv!=3),3);
    }
    return ans;
}
int main() {
    fast;
    cin>>n>>m;
    int x=0,y=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>grid[i][j];
            if(grid[i][j]=='S')x=i,y=j;
        }
    }
    bool res=0;
    res|=solve(x,y,0,-1);
    if(res)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
