#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
const int M = 1e5+9;

int n,m;
struct edge{int v,w;};
vector<edge> e[N];  // 边集,e[u][i]存储所有出边

// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)

void dfs(int u,int fa){
  for(auto ed : e[u]){
    int v=ed.v,w=ed.w;
    if(v==fa) continue;
    printf("%d,%d,%d\n",u,v,w);
    dfs(v,u);
  }
}

struct ufa{int u,fa;};
void bfs(int u,int fa){
  queue<ufa> q;
  q.push({u,fa});
  while(!q.empty()){
    u=q.front().u,fa=q.front().fa;
    q.pop();
    for(auto ed : e[u]){
      int v=ed.v,w=ed.w;
      if(v==fa) continue;
      printf("%d,%d,%d\n",u,v,w);
      q.push({v,u});
    }
  }
}

int main(){
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    e[a].push_back({b,c});
    // e[b].push_back({a,c});
  }

  // dfs(1,0);
  bfs(1,0);

  return 0;
}