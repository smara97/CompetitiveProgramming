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
vector<ll>v,seg;
const ll limit=(ll)ceil(1.5*(1e7));
vector<ll>cnt(limit,0);
ll res=1e9,mn=1e9;
void seve(ll n,ll gc){
    vector<ll>bt(limit,0);
    for(int i=gc+1;i<=limit;i++){
            if(bt[i])continue;
            ll nn=(cnt[i]);
            for(ll j=i+i;j<=limit;j+=i)bt[j]=0,nn+=(cnt[j]),bt[j]=1;
            res=min(n-nn,res);
    }
}
int main() {
    fast;
    ll n,mx=0;
   cin>>n;
   v=vector<ll>(n);ll gc=v[0];
   for(int i=0;i<n;i++)cin>>v[i],cnt[v[i]]++,gc=gcd(gc,v[i]);
   seve(n,gc);
   if(res==1e9 || res==n)cout<<-1<<endl;
   else cout<<res<<endl;
     return 0;
}
