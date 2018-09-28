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

long double dis(int x, int y, int xx, int yy) {
    return double(sqrt(pow(x - xx, 2) + pow(y - yy, 2)));
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}
vector<ll>v,cnt;
void build(int ind,int val,int mxl){
    while(ind<mxl){
        cnt[ind]+=val;
        ind+=(ind&(-ind));
    }
}
int cn(int ind){
    int ret=0;
    while(ind>0){
        ret+=cnt[ind];
        ind-=(ind&(-ind));
    }
    return ret;
}
int main() {
    fast;
    int n,q;cin>>n>>q;
    v=vector<ll>(n);
    cnt=vector<ll>(n+1,0);
    vector<pair<int,int>>qp;
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<q;i++){
        int l,r;cin>>l>>r;
        qp.push_back({l,r});
        build(l,1,n+1);build(r+1,-1,n+1);
    }
    vector<int>pu(n);
    for(int i=1;i<=n;i++){
        pu[i-1]=cn(i);
    }
    sort(pu.begin(),pu.end());
    sort(v.begin(),v.end());
    ll res=0;
    for(int i=0;i<n;i++)res+=(pu[i]*v[i]);
    cout<<res<<endl;
     return 0;
}
