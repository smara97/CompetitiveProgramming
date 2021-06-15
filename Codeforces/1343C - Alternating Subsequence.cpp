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
        int n;
        cin>>n;
        vector<ll>v(n+1);

        ll sum = 0,mx =-1e9;

        for(int i=0;i<n;i++)
            cin>>v[i];

        v[n] = 0;

        for(int i=1;i<=n;i++){

            if(v[i]>0 && v[i-1]>0 || v[i]<0 && v[i-1]<0)
                mx = max(mx,v[i-1]);

            else{
                sum +=max(mx,v[i-1]);
                mx=-1e9;
            }

        }

        cout<<sum<<endl;

    }
    return 0;
}
