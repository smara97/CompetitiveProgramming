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
struct card{
    ll fi,se,in;
};
int n;vector<card>vp;
int par[6000],memo[6000];
int solve(int ind){
    if(ind>n)return 0;
    if(memo[ind]!=-1)return memo[ind];
    int res=0;
    for(int i=1;i<=n;i++){
        if(vp[i].fi>vp[ind].fi && vp[i].se>vp[ind].se){
            if(solve(i)+1>res){
                res=solve(i)+1;
                par[ind]=i;
            }
        }
    }
    return memo[ind]=res;
}
int main() {
    fast;
    cin>>n;
    vp=vector<card>(n+1);
    memset(par,-1,sizeof par);
    memset(memo,-1,sizeof memo);
    for(int i=0;i<=n;i++){
        cin>>vp[i].fi>>vp[i].se;
        vp[i].in=i+1;
    }
    cout<<solve(0)<<endl;
    int pe=0;vector<int>pu;
    while(par[pe]!=-1){
        pu.push_back(par[pe]);
        pe=par[pe];
    }
    for(auto it:pu)cout<<it<<' ';
    cout<<endl;

    return 0;
}
