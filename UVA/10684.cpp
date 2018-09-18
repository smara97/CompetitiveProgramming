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
int n;
int lis[1000];
int memo[1000];
int solve(int ind,int prv) {
    if(ind >=n)return 0;
    if(ind>=0)
        if(memo[ind]!=-1)return memo[ind];
    int ans=0;
    for(int i=ind+1; i<n; i++) {
        if(lis[i]>prv) {
            ans=max(ans,solve(i,lis[i])+1);
        }
    }
    return memo[ind]=ans;
}
int main() {
    fast;
    ll num;
    while(cin>>num){
        if(!num)break;
        vector<ll>v(num);
        ll res=INT_MIN,cur=0;
        for(int i=0;i<num;i++)cin>>v[i];
        for(int i=0;i<num;i++){
            cur=max(cur+v[i],v[i]);
            res=max(res,cur);
        }
        if(res<=0)cout<<"Losing streak."<<endl;
        else cout<<"The maximum winning streak is "<<res<<"."<<endl;
    }
    return 0;

}
