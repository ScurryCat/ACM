#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;

int n,m,s,a,b;
vector<int> e[N];
int dep[N], fa[N][20];

void dfs(int father, int u){
  dep[u]=dep[father]+1;
  fa[u][0]=father;
  for(int i=1;i<20;i++){
    fa[u][i]=fa[fa[u][i-1]][i-1];
  }

  for(int v : e[u]){
    if(v!=father) dfs(u,v);
  }
}

int lca(int u, int v){
  if(dep[u]<dep[v]) swap(u,v);
  for(int i=19;i>=0;i--){
    if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
  }
  if(u==v) return v;
  for(int i=19;i>=0;i--){
    if(fa[u][i]!=fa[v][i]){
      u=fa[u][i];
      v=fa[v][i];
    }
  }
  return fa[u][0];
}

int main(){
  int n; cin>>n;
  for(int i=1;i<n;i++){
    int u, v; cin>>u>>v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(0,1);
  for(int i=1;i<=n;i++){
    for(int j=0;j<=3;j++){
      cout<<fa[i][j]<<' ';
    }
    cout<<'\n';
  }
  return 0;
}