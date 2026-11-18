#include <bits/stdc++.h>
using namespace std;

#define rc u<<1
#define lc u<<1|1

typedef long long ll;
const int N = 1e5+9;

int n,m,r,p;
int fa[N],son[N],dep[N],top[N],sz[N];
int w[N],nw[N],id[N],idx;
int h[N],to[N<<1],ne[N<<1],tot;
struct{int l,r;ll sum,add;}tr[N<<2];

inline void add(int u,int v){
  to[++tot]=v; ne[tot]=h[u]; h[u]=tot;
}

inline void dfs1(int u,int f){
  fa[u]=f; dep[u]=dep[f]+1; sz[u]=1;
  for(int i=h[u];~i;i=ne[i]){
    int v=to[i];
    if(v==f) continue;
    dfs1(v,u);
    sz[u]+=sz[v];
    if(sz[son[u]]<sz[v]) son[u]=v;
  }
}

inline void dfs2(int u,int t){
  top[u]=t; id[u]=++idx; nw[idx]=w[u];
  if(!son[u]) return;
  dfs2(son[u],t);
  for(int i=h[u];~i;i=ne[i]){
    int v=to[i];
    if(v==fa[u] || v==son[u]) continue;
    dfs2(v,v);
  }
}

inline void pushup(int u){
  tr[u].sum=(tr[lc].sum+tr[rc].sum) % p;
}

inline void pushdown(int u){
  if(tr[u].add){
    tr[lc].add = (tr[lc].add+tr[u].add) % p;
    tr[rc].add = (tr[rc].add+tr[u].add) % p;
    tr[lc].sum = (tr[lc].sum+tr[u].add*(tr[lc].r-tr[lc].l+1)) % p;
    tr[rc].sum = (tr[rc].sum+tr[u].add*(tr[rc].r-tr[rc].l+1)) % p;
    tr[u].add = 0;
  }
}

inline void build(int u,int l,int r){
  tr[u]={l,r,nw[l],0};
  if(l==r) return;
  int m=l+r>>1;
  build(lc,l,m);
  build(rc,m+1,r);
  pushup(u);
}

inline void update(int u,int x,int y,ll k){
  if(x<=tr[u].l && tr[u].r<=y){
    tr[u].add = (tr[u].add+k) % p;
    tr[u].sum = (tr[u].sum+k*(tr[u].r-tr[u].l+1)) % p;
    return;
  }
  pushdown(u);
  int m=tr[u].l+tr[u].r>>1;
  if(x<=m) update(lc,x,y,k);
  if(y>m) update(rc,x,y,k);
  pushup(u);
}

inline ll query(int u,int x,int y){
  if(x<=tr[u].l && tr[u].r<=y) return tr[u].sum;
  pushdown(u);
  int m=tr[u].l+tr[u].r>>1;
  ll r=0;
  if(x<=m) r = (r+query(lc,x,y)) % p;
  if(y>m) r = (r+query(rc,x,y)) % p;
  return r;
}

inline void updatepath(int u,int v,ll k){
  while(top[u]!=top[v]){
    if(dep[top[u]]<dep[top[v]]) swap(u,v);
    update(1,id[top[u]],id[u],k);
    u=fa[top[u]];
  }
  if(dep[u]<dep[v]) swap(u,v);
  update(1,id[v],id[u],k);
}

inline ll querypath(int u,int v){
  ll r=0;
  while(top[u]!=top[v]){
    if(dep[top[u]]<dep[top[v]]) swap(u,v);
    r = (r+query(1,id[top[u]],id[u])) % p;
    u = fa[top[u]];
  }
  if(dep[u]<dep[v]) swap(u,v);
  r = (r+query(1,id[v],id[u])) % p;
  return r;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  memset(h,-1,sizeof h);
  cin>>n>>m>>r>>p;
  for(int i=1;i<=n;i++) cin>>w[i];
  for(int i=1;i<n;i++){
    int u,v; cin>>u>>v;
    add(u,v);
    add(v,u);
  }
  dfs1(r,0);
  dfs2(r,r);
  build(1,1,n);
  while(m--){
    int op; cin>>op;
    if(op==1){
      int x,y,z; cin>>x>>y>>z;
      updatepath(x,y,z);
    }
    if(op==2){
      int x,y; cin>>x>>y;
      cout<<querypath(x,y)<<'\n';
    }
    if(op==3){
      int x,y; cin>>x>>y;
      update(1,id[x],id[x]+sz[x]-1,y);
    }
    if(op==4){
      int x; cin>>x;
      cout<<query(1,id[x],id[x]+sz[x]-1)<<'\n';
    }
  }
}