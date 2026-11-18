#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6+9;

inline void solve(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n+1), b(m+1);

  for(int i=1; i<=n; i++) cin >> a[i];
  for(int i=1; i<=m; i++) cin >> b[i];

  int ans = 0;
  ll sa = a[1], sb = b[1];
  for(int i=1, j=1; i<=n && j<=m; ){
    if(sa == sb){
      i++, j++;
      if(i <= n) sa = a[i];
      if(j <= m) sb = b[j];
    }
    else if(sa < sb){
      i++;
      ans++;
      sa += a[i];
    }
    else{
      j++;
      ans++;
      sb += b[j];
    }
  }
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