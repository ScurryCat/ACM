#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline void solve(){
  int a[6];
  for(int i=0;i<6;i++) cin>>a[i];
  int res = 0;
  for(int i=0;i<3;i++) 
    if(a[i] == a[i+3]) 
      res++;
  cout<<res;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t = 1;
  // cin >> t;
  while(t--) solve();

  return 0;
}