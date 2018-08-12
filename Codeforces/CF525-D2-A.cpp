#define _CRT_SECURE_NO_WARINGS
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define PI 3.14159265;
#define endl '\n'
typedef long long ll;
using namespace std;
int main() {
  fast;
  int n;
  cin>>n;
  cin.ignore();
  string s;
  cin>>s;
  int res=0;
  map<char,int>mp;
  for(int i=0;i<s.length();i++){
      if(s[i]>='a')mp[s[i]]++;
      else {
          if(!mp[char(s[i]+32)])res++;
          else mp[char(s[i]+32)]--;
      }
  }
  cout<<res<<endl;
  return 0;
}
