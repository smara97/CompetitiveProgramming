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
bitset<10000000>bt;
vector<ll>prim;
void seve() {
    ll num=1e7;
    bt.set();bt[0]=bt[1]=0;
    for(ll i=2;i<=num;i++){
        if(bt[i]){
         for(ll j=i*i;j<=num;j+=i)bt[j]=0;
            prim.push_back(ll(i));
        }
    }
}
void pf(ll num){
    bool ng=bool(num<0);
    ll res=num;
    num=abs(num);
    vector<ll>pfi;
    ll ind=0,pfv=prim[0];
    while(pfv*pfv<=abs(num)){
        while((num)%pfv==0){num/=pfv;pfi.push_back(pfv);}
        ind++;pfv=prim[ind];
    }
    if(abs(num)!=1)pfi.push_back(abs(num));
    cout<<res<<" = ";
    if(ng)pfi.push_back(-1);
    sort(pfi.begin(),pfi.end());
    for(int i=0;i<pfi.size();i++){
        if(i)cout<<" x ";
        cout<<pfi[i];
    }
    cout<<endl;
}
int main() {
    fast;
    seve();
    ll num;
    while(cin>>num){
        if(!num)break;
        pf(num);
    }
    return 0;

}
