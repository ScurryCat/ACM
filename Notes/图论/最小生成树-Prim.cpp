#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+9, inf = 1e9;

int n, m;
int d[N], vis[N];
int cnt, ans;

struct edge{int v, w;};
vector<edge> e[N];

bool prim(int s){ // 贪心思想
  for(int i=0; i<=n; i++) d[i] = inf, vis[i] = 0;
  d[s] = 0;
  priority_queue<pair<int, int>> q;
  q.push({-d[s], s});
  while(q.size()){
    int u = q.top().second; q.pop();
    if(vis[u]) continue;
    vis[u] = 1;
    cnt++;
    ans += d[u];
    for(auto [v, w] : e[u]){
      if(!vis[v] && d[v] > w){
        d[v] = w;
        q.push({-d[v], v});
      }
    }
  }
  return cnt == n;
}

int main(){
  cin >> n >> m;
  for(int i=1; i<=m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, w});
    e[v].push_back({u, w});
  }
  if(prim(1)) cout << ans << '\n';
  else cout << "orz\n";
  return 0;
}