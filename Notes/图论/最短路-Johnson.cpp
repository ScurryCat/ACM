#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 9;
using ll = long long;

int n, m;

struct Johnson{
  struct edge{int v, w;};
  vector<edge> e[N];
  int h[N], d[N], cnt[N] = {0}, vis[N] = {0};

  bool spfa(int s){
    memset(h, 0x3f, sizeof h);
    queue<int> q;
    q.push(s); h[s] = 0; vis[s] = 1;
    while(q.size()){
      int u = q.front(); q.pop(); vis[u] = 0;
      for(auto [v, w] : e[u]){
        if(h[v] > h[u] + w){
          h[v] = h[u] + w;
          cnt[v] = cnt[u] + 1;
          if(cnt[v] > n) return 1;
          if(!vis[v]) q.push(v), vis[v] = 1;
        }
      }
    }
    return 0;
  }

  void dijkstra(int s){
    memset(d, 0x3f, sizeof d);
    memset(vis, 0, sizeof vis);
    priority_queue<pair<int, int>> q;
    q.push({-d[s], s}); d[s] = 0;
    while(q.size()){
      int u = q.top().second;
      q.pop();
      if(vis[u]) continue;
      vis[u] = 1;
      for(auto [v, w] : e[u]){
        if(d[v] > d[u] + w){
          d[v] = d[u] + w;
          if(!vis[v]) q.push({-d[v], v});
        }
      }
    }
  }

  void johnson(){
    for(int i=1; i<=n; i++) e[0].push_back({i, 0});
    if(spfa(0)){
      cout << "-1\n";
      return;
    }
    for(int u=1; u<=n; u++){
      for(auto &[v, w] : e[u]){
        w += h[u] - h[v];
      }
    }
    for(int u=1; u<=n; u++){
      dijkstra(u);
      ll ans = 0;
      for(int v=1; v<=n; v++){
        if(d[v] == 0x3f3f3f3f) ans += 1ll * v * 1e9;
        else ans += 1ll * v * (d[v] - h[u] + h[v]);
      }
      cout << ans << '\n';
    }
  }
};

Johnson jhs;

int main(){
  cin >> n >> m;
  for(int i=1; i<=m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    jhs.e[u].push_back({v, w});
  }
  jhs.johnson();
  return 0;
}