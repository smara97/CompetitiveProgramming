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
        vector<pair<int,int>>vp;
        pair<int,int>pOdds,pEvens;
        for(int i=0;i<n*2;i++){
            int x;
            cin>>x;
            if(x%2){
                if(pOdds.first){
                    pOdds.second=i+1;
                    vp.push_back(pOdds);
                    pOdds.first=0;
                }
                else pOdds.first = i+1;
            }
            else {
                 if(pEvens.first){
                    pEvens.second=1+i;
                    vp.push_back(pEvens);
                    pEvens.first=0;
                }
                else pEvens.first = i+1;
            }
        }
        for(int i=0;i<n-1;i++)
            cout<<vp[i].first<<' '<<vp[i].second<<endl;
    }
    return 0;
}
