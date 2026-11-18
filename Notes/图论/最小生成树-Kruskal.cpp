#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+9, inf = 1e9;

int n, m;
int fa[N];
int ans, cnt;

struct edge{
  int u, v, w;
  bool operator<(const edge &t) const{
    return w < t.w;
  }
}e[N];

int find(int x){
  if(x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}

bool kruskal(int s){  // 利用并查集
  for(int i=1; i<=n; i++) fa[i] = i;
  sort(e+1, e+m+1); // 算法瓶颈
  for(int i=1; i<=m; i++){
    int x = find(e[i].u);
    int y = find(e[i].v);
    if(x != y){
      fa[x] = y;
      ans += e[i].w;
      cnt++;
    }
  }
  return cnt == n-1;
}

int main(){
  cin >> n >> m;
  for(int i=1; i<=m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    e[i] = {u, v, w};
  }
  if(kruskal(1)) cout << ans << '\n';
  else cout << "orz\n";

  return 0;
}