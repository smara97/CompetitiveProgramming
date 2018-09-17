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
string s;
ll bck[150];
int res=0;
void solve(string cur,int ind){
    if(ind>=(int)s.length())return ;
    res+=bool(cur=="QAQ");
    if(cur.length()>3)return ;
    for(int i=ind+1;i<=s.length();i++){
        if(bck[i]==0){
            bck[i]=1;
            solve(cur+s[i],i);
            bck[i]=0;
        }
    }
}
int main() {
    fast;
    cin>>s;
    solve("",-1);
    cout<<res<<endl;
    return 0;

}
