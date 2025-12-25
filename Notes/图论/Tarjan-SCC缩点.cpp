#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9, M = 5e5+9;

int h[N],to[M],ne[M],tot=1;
int stk[N],instk[N],top;
int dfn[N],low[N],idx;
int scc[N],siz[N],cnt;

inline void add(int u,int v){
  to[++tot]=v; ne[tot]=h[u]; h[u]=tot;
}

inline void tarjan(int u){
  dfn[u]=low[u]=++idx;
  stk[++top]=u; instk[u]=1;
  for(int i=h[u];i;i=ne[i]){
    int v=to[i];
    if(!dfn[v]) tarjan(v);
    if(!instk[v]) continue;
    low[u]=min(low[u],low[v]);
  }
  if(scc[u]==low[u]){
    int v=0; cnt++;
    while(u!=v){
      v=stk[top--]; instk[v]=0;
      siz[cnt]++;
      scc[v]=cnt;
    }
  }
}

int main(){

  return 0;
}