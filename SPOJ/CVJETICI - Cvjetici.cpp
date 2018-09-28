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
vector<ll>v(1e5+5,0);
void build(int ind,int val){
    while(ind<=1e5){
        v[ind]+=val;
        ind+=(ind&(-ind));
    }
}
int res(int ind){
    int ret=0;
    while(ind>0){
        ret+=v[ind];
        ind-=(ind&(-ind));
    }
    return ret;
}
int main() {
    fast;
    int n;cin>>n;
    vector<ll>cnt(1e5+5,0);
    for(int i=0;i<n;i++){
        int l,r;cin>>l>>r;
        int q1=res(l),q2=res(r);
        cout<<q1+q2-cnt[l]-cnt[r]<<endl;
        cnt[l]=q1,cnt[r]=q2;
        build(l+1,1);
        build(r,-1);
    }
     return 0;
}
