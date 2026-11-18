#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6+9;

int w[N], h[N], to[N], ne[N], idx;

inline void add(int u,int v){
  to[++idx]=v; ne[idx]=h[u]; h[u]=idx;
}

inline void solve(){
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; i++) cin >> w[i];
  for(int i=1; i<=m; i++){
    int u, v;
    cin >> u >> v;
    add(u, v);
    add(v, u);
  }

  

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