#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6+9;

inline void solve(){
  int n; cin >> n;
  map<int,int> a;
  for(int i=1; i<=n; i++){
    int x;
    cin >> x;
    a[x]++;
  }
  int cnt = 0, ans = 0;
  for(auto it : a){
    if(it.second == 1) cnt++;
  }
  for(auto it : a){
    if(it.second >= 2){
      if(cnt){
        int x = max(0, cnt - (it.second - 2));
        ans += cnt - x;
        cnt = x;
      }
      else{
        ans += it.second - 2;
      }
    }
  }
  ans += cnt / 2;
  cout << ans;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t = 1;
  // cin >> t;
  while(t--){
    solve();
  }

  return 0;
}