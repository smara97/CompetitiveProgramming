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

float dist(int x1,int y1,int x2,int y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

int main()
{
    fast;
    int ts;
    cin>>ts;
    while(ts--){
        int n,k;
        cin>>n>>k;
        if((n-(k-1)*2)%2==0 && (n-(k-1)*2)>0){
        cout<<"YES"<<endl;
            for(int i=0;i<k-1;i++)
                cout<<2<<' ';
            cout<<n-(2*(k-1))<<endl;
        }
        else if((n-(k-1))%2==1 && (n-(k-1))>0){
        cout<<"YES"<<endl;
         for(int i=0;i<k-1;i++)
                cout<<1<<' ';
            cout<<n-(k-1)<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
