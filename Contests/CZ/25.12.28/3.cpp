#include <bits/stdc++.h>
using namespace std;

inline void solve(){
  int n; cin>>n;
  vector<int> a(n+1), f(n+1);
  unordered_map<int,vector<int>> mp;
  int mx=0, ans=0;
  for(int i=1;i<n;i++) cin>>a[i];
  f[1]=1;
  for(int i=2;i<n;i++){
    if(a[i] == a[i-1]+1) f[i] = f[i-1] + 1;
    else{
      f[i]=1;
      mx = max(mx, f[i-1]);
      mp[f[i-1]].push_back(i-f[i-1]);
    }
    if(i == n-1){
      mx = max(mx, f[i]);
      mp[f[i]].push_back(i-f[i]+1);
    }
  }

  // for(auto x : mp){
  //   cout<<x.first<<':';
  //   for(auto y : x.second) cout<<y<<' ';cout<<'\n';
  // }

  for(auto x : mp[mx]){
    cout<<x<<' '<<a[x+mx-1]<<'\n';
    int res = f[x+mx-1];
    if(a[x]>1){
      int y = a[x]-1;
      res = max(res, f[x+mx-1]+1);  
      if(a[x-1]+1==y) res = max(res, f[x-1]+f[x+mx-1]+1);
    }
    if(a[x+mx-1]<n){
      int y = a[x+mx-1]+1;
      int i = x+mx;
      while(f[i]<f[i+1]) i++;
      res = max(res, f[x+mx-1]+1);
      if(a[x+mx]-1==y) ans = max(res, f[i]+f[x+mx-1]+1);
    }

    ans = max(ans, res);
  }
  if(n==2) ans=2;
  cout<<ans<<'\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t; cin>>t;
  while(t--) solve();

  return 0;
}