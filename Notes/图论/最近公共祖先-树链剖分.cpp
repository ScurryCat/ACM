#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+9;

int n,m,s;
vector<int> e[N];
int fa[N], dep[N], son[N], sz[N];
int top[N];

// 树链剖分,算法思想：对于每个父节点，区分出它的重儿子与轻儿子，

void dfs1(int u,int father){ // 第一次dfs，先找到每个点的父节点、深度、以及它的重儿子
  fa[u]=father; dep[u]=dep[father]+1; sz[u]=1;
  for(int v : e[u]){
    if(v==father) continue;
    dfs1(v,u);
    sz[u]+=sz[v];
    if(sz[son[u]]<sz[v]) son[u]=v;
  }
}

void dfs2(int u,int t){ // 第二次dfs，找到每个点所在链的链头
  top[u]=t;
  if(!son[u]) return; // 无重儿子则直接返回 (叶子节点)
  dfs2(son[u],t);
  for(int v:e[u]){
    if(v==fa[u] || v==son[u]) continue;
    dfs2(v,v); // 搜轻儿子
  }
}

int lca(int u,int v){
  while(top[u]!=top[v]){
    if(dep[top[u]]<dep[top[v]]) swap(u,v);
    u=fa[top[u]];
  }
  return dep[u]<dep[v]?u:v;
}

int main(){
  cin>>n>>m>>s;
  for(int i=1;i<n;i++){
    int u, v; cin>>u>>v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs1(s,0);
  dfs2(s,s);
  while(m--){
    int u,v; cin>>u>>v;
    cout<<lca(u,v)<<'\n';
  }
  return 0;
}