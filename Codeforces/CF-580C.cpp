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

vector<vector<int>>ad;
vector<bool>vis;
vector<bool>cnt;
vector<int>cats,ok;
vector<int>par;
void BFS(int u,int m) {
    queue<int>q;
    q.push(u);
    while(q.size()) {
        int v=q.front();
        q.pop();
        vis[v]=1;
        if(cnt[par[v]])cnt[v]=1;
        else {
            if(ok[v]) {
                cats[v]+=cats[par[v]];
                if(cats[v]>m)cnt[v]=1;
            } else cats[v]=ok[v];
        }
        for(int i=0; i<ad[v].size(); i++) {
            int uv=ad[v][i];
            if(!vis[uv]) {
                par[uv]=v;
                q.push(uv);
            }

        }

    }

}
int main() {
    fast;
    int n,m;
    cin>>n>>m;
    ad=vector<vector<int>>(n+1);
    cnt=vis=vector<bool>(n+1,0);
    cats=ok=par=vector<int>(n+1);
    for(int i=1; i<=n; i++) {
        cin>>ok[i];
        cats[i]=ok[i];
    }
    for(int i=0; i<n-1; i++) {
        int u,v;
        cin>>u>>v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    BFS(1,m);
    int res=0;
    for(int i=1; i<=n; i++) {
        if(ad[i].size()==1 && !cnt[i] && i!=1)res++;
    }
    cout<<res<<endl;
    return 0;
}
