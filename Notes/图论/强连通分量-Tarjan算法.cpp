#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+9;

int n,m;
int h[N],to[N],ne[N],tot;
int dfn[N],low[N],idx;
int stk[N],instk[N],top;
int scc[N],siz[N],cnt;

inline void tarjan(int u){
  // 1.打时间戳，入栈
  dfn[u]=low[u]=++idx; 
  stk[++top]=u; instk[u]=1;

  // 2.遍历子节点，更新时间戳
  for(int i=h[u];~i;i=ne[i]){
    int v=to[i];
    if(!dfn[v]){ // 如果v尚未访问
      tarjan(v); // 递归访问v
      low[u]=min(low[u],low[v]); // 返回时更新最早时间戳
    }
    else if(instk[v]){ // 如果v已访问过，且仍在栈中
      low[u]=min(low[u],dfn[v]); // 更新时间戳, 注意！！！ 这里的dfn[v]在求强连通分量时可以替换成low[v]，在求双连通分量时，必须这样写 
    }
  }

  // 3.返回时，试图记录scc
  if(dfn[u]==low[u]){ // 当前时间戳与最早时间戳相同，说明u是scc的根节点
    int v=0; cnt++;
    while(u!=v){
      v=stk[top--]; instk[v]=0;
      scc[v]=cnt;
      siz[cnt]++;
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);


  return 0;
}