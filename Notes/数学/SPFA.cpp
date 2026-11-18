#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

class SPFA{
  private:
  
  int n, m;
  struct edge{int v, w;};
  vector<edge> e[N];
  int d[N], cnt[N], vis[N];

  public:

  SPFA(){
    memset(cnt, 0, sizeof cnt);
    memset(vis, 0, sizeof vis);
    cin >> n >> m;
    for(int i=1; i<=m; i++){
      int u, v, w;
      cin >> u >> v >> w;
      e[u].push_back({v, w});
      if(w >= 0) e[v].push_back({u, w});
    }
    if(spfa(1)) cout << "YES\n";
    else cout << "NO\n";
  }

  bool spfa(int s){
    memset(d, 0x3f, sizeof d);
    queue<int> q; q.push(s);
    d[s] = 0; vis[s] = 1;
    while(q.size()){
      int u = q.front(); q.pop(); vis[u] = 0;
      for(auto [v, w] : e[u]){
        if(d[v] > d[u] + w){
          d[v] = d[u] + w;
          cnt[v] = cnt[u] + 1;
          if(cnt[v] >= n) return true;
          if(!vis[v]) q.push(v), vis[v] = 1;
        }
      }
    }
    return false;
  }

};

int main(){
  int t; cin >> t;
  while(t--) SPFA();
  return 0;
}