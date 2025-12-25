#include <bits/stdc++.h>
using namespace std;

int t_=1;

#ifndef ONLINE_JUDGE
#define LOCAL
#define debug(x) cerr<<t_<<':'<<#x<<'='<<x<<'\n';
#endif

inline void qwq_(){
  string s; cin>>s;
  unordered_map<string,int> mp;
  int ans=0;
  for(int i=0;i<s.size();i++){
    string a;
    for(int j=i;j<s.size();j++){
      a+=s[j];
      if(!mp[a]){
        mp[a]=1;
        ans++;
      }
    }
  }
  cout<<ans;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  #ifdef LOCAL
  freopen("1.in","r",stdin);
  freopen("1.out","w",stdout);
  #endif
  int yyy = 1;
  // cin >> yyy;
  while(yyy--){
    qwq_();
    t_+=1;
  }
  return 0;
}