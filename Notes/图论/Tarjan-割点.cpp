#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9, M = 5e5+9;

int h[N],to[M],ne[M],tot=1;
int dfn[N],low[N],idx;
int cut[N],root;

inline void add(int u,int v){
  to[++tot]=v; ne[tot]=h[u]; h[u]=tot;
}

inline void tarjan(int u){
  dfn[u]=low[u]=++idx;
  int child=0;
  for(int i=h[u];i;i=ne[i]){
    int v=to[i];
    if(!dfn[v]){
      tarjan(v);
      low[u]=min(low[u],low[v]);
      if(low[v]>=dfn[u]){ // 判断割点
        child++; // 子树个数
        if(u!=root || child>1){
          cut[u]=1;
        }
      }
    }
    else{
      low[u]=min(low[u],dfn[v]);
    }
  }
}

int main(){

  return 0;
}