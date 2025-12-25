#include <bits/stdc++.h>
using namespace std;

#define lc u<<1
#define rc u<<1|1

typedef long long ll;

const int N = 2e5+9;

int w[N];
vector<int> e[N];
int fa[N],son[N],dep[N],top[N],sz[N];
int nw[N],id[N],idx;
struct node{
  int l,r;
  ll sum,add;
}tr[N<<2];

void dfs1(int u,int f){
  fa[u]=f; dep[u]=dep[f]+1; sz[u]=1;
  for(int v : e[u]){
    if(v==f) continue;
    dfs1(v,u);
    sz[u]+=sz[v];
    if(sz[son[u]]<sz[v]) son[u]=v;
  }
}

void dfs2(int u,int t){
  top[u]=t; id[u]=++idx; nw[idx]=w[u];
  if(!son[u]) return;
  dfs2(son[u],t);
  for(int v : e[u]){
    if(v==fa[u] || v==son[u]) continue;
    dfs2(v,v);
  }
}

void pushup(int u){
  tr[u].sum=tr[lc].sum+tr[rc].sum;
}

void pushdown(int u){
  if(tr[u].add){
    tr[lc].sum+=tr[u].add*(tr[lc].r-tr[lc].l+1);
    tr[rc].sum+=tr[u].add*(tr[rc].r-tr[rc].l+1);
    tr[lc].add+=tr[u].add;
    tr[rc].add+=tr[u].add;
    tr[u].add=0;
  }
}

void build(int u,int x,int y){
  tr[u]={x,y,nw[x],0};
  if(x==y) return;
  int m=x+y>>1;
  build(lc,x,m);
  build(rc,m+1,y);
  pushup(u);
}

ll query(int u,int x,int y){
  if(x<=tr[u].l && tr[u].r<=y) return tr[u].sum;
  pushdown(u);
  int m=tr[u].l+tr[u].r>>1;
  ll r=0;
  if(x<=m) r+=query(lc,x,y);
  if(y>m) r+=query(rc,x,y);
  return r;
}

ll querypath(int u,int v){
  ll r=0;
  while(top[u]!=top[v]){
    if(dep[top[u]]<dep[top[v]]) swap(u,v);
    r+=query(1,id[top[u]],id[u]);
    u=fa[top[u]];
  }
  if(dep[u]<dep[v]) swap(u,v);
  r+=query(1,id[v],id[u]);
  return r;
}

void update(int u,int x,int y,int k){
  if(x<=tr[u].l && tr[u].r<=y){
    tr[u].add+=k;
    tr[u].sum+=k*(tr[u].r-tr[u].l+1);
    return;
  }
  pushdown(u);
  int m=tr[u].l+tr[u].r>>1;
  if(x<=m) update(lc,x,y,k);
  if(y>m) update(rc,x,y,k);
  pushup(u);
}

void updatepath(int u,int v,int k){
  while(top[u]!=top[v]){
    if(dep[top[u]]<dep[top[v]]) swap(u,v);
    update(1,id[top[u]],id[u],k);
    u=fa[top[u]];
  }
  if(dep[u]<dep[v]) swap(u,v);
  update(1,id[v],id[u],k);
}

ll queryroot(int u){
  return query(1,id[u],id[u]+sz[u]);
}

void updateroot(int u,int k){
  update(1,id[u],id[u]+sz[u],k);
}

int main(){

  return 0;
}