#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+9;

int n,m;
int w[N][N];
bool vis[N];  // 判重

void dfs(int u){
  vis[u]=true;
  for(int v=1;v<=n;v++){
    if(w[u][v]){
      printf("%d,%d,%d\n",u,v,w[u][v]);
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
    for(int v=1;v<=n;v++){
      if(w[u][v]){
        printf("%d,%d,%d\n",u,v,w[u][v]);
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
    w[a][b]=c;
    // w[b][a]=c; // 若无向，双向储存
  }
  // dfs(1);
  bfs(1);

  return 0;
}