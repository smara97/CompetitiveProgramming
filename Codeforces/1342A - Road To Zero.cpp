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
        ll x,y,a,b;
        ll res =0 ;
        cin>>x>>y>>a>>b;

        if(2*a<b)
            b=2*a;

        if(x >0 && y>0 || x<0 &&  y<0){
            x = abs(x) ,y =abs(y);
            res+=min(x,y)*b;
            res+=max(y-x,x-y)*a;
        }
        else{
            res+=max(abs(x),abs(y))*a;
        }
        cout<<res<<endl;
    }
    return 0;
}
