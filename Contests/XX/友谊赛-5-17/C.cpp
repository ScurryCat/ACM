#include <bits/stdc++.h>
using namespace std;

inline void solve(){
  int n, k; cin >> n >> k;
  map<int, int> f;
  for(int i=1; i<=n; i++){
    int w, t; cin >> w >> t;
    f[k - w + t]++; // 记录不阻塞情况下的理想完工时间
  }
  int ans = 0;
  for(auto it : f){
    int x = it.first, y = it.second;
    ans = max(ans, x - 1) + y;
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t=1;
  cin >> t;
  while(t--){
    solve();
  }

  return 0;
}