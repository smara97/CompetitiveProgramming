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
        string str;
        cin>>n>>str;
        int ops =0,clos = 0;
        for(int i=0;i<n;i++){
            if(str[i]==')'){
                if(ops)
                    ops--;
                else
                    clos++;
            }
            else
                ops++;
        }
        cout<<clos<<endl;
    }
    return 0;
}
