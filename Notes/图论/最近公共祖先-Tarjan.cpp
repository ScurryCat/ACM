#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;

int n,m,s;
vector<int> e[N];
int fa[N], vis[N], ans[N];
vector<pair<int,int>> q[N];

// Tarjan算法是一种离线算法，利用并查集的思想，时间复杂度O(n+m)

int find(int u){
  if(u==fa[u]) return u;
  return fa[u]=find(fa[u]);
}

void tarjan(int u){
  vis[u]=1;
  for(int v : e[u]){
    if(vis[v]) continue;
    tarjan(v);
    fa[v]=u;
  }
  for(auto it : q[u]){
    int v=it.first, x=it.second;
    if(vis[v]) ans[x]=find(v);
  }
}

int main(){
  cin>>n>>m>>s;
  for(int i=1;i<=n;i++) fa[i]=i;
  for(int i=1;i<n;i++){
    int u, v; cin>>u>>v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for(int i=1;i<=m;i++){
    int u, v; cin>>u>>v;
    q[u].push_back({v,i});
    q[v].push_back({u,i});
  }
  tarjan(s);
  for(int i=1;i<=m;i++) cout<<ans[i]<<'\n';
  return 0;
}