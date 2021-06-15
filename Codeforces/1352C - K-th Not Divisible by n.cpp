#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0);cin.tie(NULL),cout.tie(NULL)
#define ll long long
#define EPS 1e-9
using namespace std;

int dist(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}

int main()
{
    fast;
    int ts;
    cin>>ts;
    while(ts--){
        ll n,k;
        cin>>n>>k;

        int part = ceil(double(k)/double(n-1));
        cout<<(part-1)*n + k%(n-1)+bool(k%(n-1)==0)*(n-1)<<endl;

    }
    return 0;
}
