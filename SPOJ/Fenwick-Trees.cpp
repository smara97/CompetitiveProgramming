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
vector<ll>v;
void update(int ind,int val,int mxl){
    while(ind<mxl){
        v[ind]+=val;
        ind+=(ind&(-ind));
    }
}
ll getsum(int ind){
    ll sum=0;
    while(ind>0){
        sum+=v[ind];
        ind-=(ind&(-ind));
    }
    return sum;
}
int main() {
    fast;
    int n;cin>>n;
    v=vector<ll>(n+1);
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        update(i,x,n+2);
    }
    int q;cin>>q;
    while(q--){
        char x;int l,r;
        cin>>x>>l>>r;
        if(x=='q')cout<<getsum(r)-getsum(l-1)<<endl;
        else update(l,r,n+1);
    }
     return 0;
}
