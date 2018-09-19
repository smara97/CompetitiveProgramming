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
    ll n,m;
    cin>>n>>m;
    ll po=n*n;
    vector<pair<ll,ll>>vp(m);
    for(int i=0;i<m;i++)
        cin>>vp[i].first>>vp[i].second;
    bool row[1000005],col[1000005];
    ll dnr=n,dnc=n;
    for(int i=0;i<m;i++){
        ll mult=0;
        if(!row[vp[i].first])dnr--;
        if(!col[vp[i].second])dnc--;
        row[vp[i].first]=col[vp[i].second]=1;
        cout<<dnr*dnc<<' ';
    }
    cout<<endl;
    return 0;
}
