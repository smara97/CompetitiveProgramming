#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0);cin.tie(NULL),cout.tie(NULL)
#define EPS 1e-9
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int  dix[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int  diy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

using namespace std;


int main()
{
    fast;
    int ts;
    cin>>ts;
    while(ts--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];

        sort(v.begin(),v.end());
        int res=0;
        for(int i=1;i<=n*2;i++){
            int begi=0,endi=n-1,cnt=0;

            while(begi<endi){
                if(v[begi]+v[endi]==i)cnt++,begi++,endi--;
                else if(v[begi]+v[endi]>i)endi--;
                else begi++;
            }
            res =max(res,cnt);
        }
        cout<<res<<endl;
    }
    return 0;
}
