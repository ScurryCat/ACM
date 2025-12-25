#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
const int M = 1e5+9;

int n,m;
struct edge{
  int u,v,w;
}e[N];
bool vis[N];

// 时间复杂度：O(nm)
// 空间复杂度：O(m)

void dfs(int u){
  vis[u]=true;
  for(int i=1;i<=m;i++){
    if(e[i].u==u){
      int v=e[i].v,w=e[i].w;
      printf("%d,%d,%d\n",u,v,w);
      if(vis[v]) continue;
      dfs(v);
    }
  }  
}

void bfs(int u){
  queue<int> q;
  q.push(u);
  while(!q.empty()){
    u=q.front();
    vis[u]=true;
    q.pop();
    for(int i=1;i<=m;i++){
      if(e[i].u==u){
        int v=e[i].v,w=e[i].w;
        printf("%d,%d,%d\n",u,v,w);
        if(vis[v]) continue;
        q.push(v);
      }
    }
  }
}

int main(){
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    e[i]={a,b,c};
    // e[i]={b,a,c};
  }

  dfs(1);
  // bfs(1);

  return 0;
}