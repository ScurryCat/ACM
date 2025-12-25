#include <bits/stdc++.h>
using namespace std;

#define lc p<<1
#define rc p<<1|1

const int N = 5e5+9;

int n,w[N];
struct node{
  int l,r,sum,add;
}tr[4*N];

void pushup(int p){ // 向上更新
  tr[p].sum=tr[lc].sum+tr[rc].sum;
}

void pushdown(int p){ // 向下更新
  if(tr[p].add){
    tr[lc].sum+=tr[p].add*(tr[lc].r-tr[lc].l+1);
    tr[rc].sum+=tr[p].add*(tr[rc].r-tr[rc].l+1);
    tr[lc].add+=tr[p].add;
    tr[rc].add+=tr[p].add;
    tr[p].add=0;
  }
}

void build(int p,int l,int r){ // 递归建树，O(n)
  tr[p]={l,r,w[l],0};
  if(l==r) return;
  int m=l+r>>1;
  build(lc,l,m);
  build(rc,m+1,r);
  pushup(p);
} 

void update(int p,int x,int k){ // 单点修改,O(logn)
  if(tr[p].l==tr[p].r){
    tr[p].sum+=k;
    return;
  }
  int m=tr[p].l+tr[p].r>>1;
  if(x<=m) update(lc,x,k);
  else update(rc,x,k);
  pushup(p);
}

// 区间修改：引入懒标记，当修改区间直接覆盖线段长度时，先记录下区间修改值，然后直接返回答案。只有当询问/修改区间未被覆盖到时，下传修改。
void update(int p,int x,int y,int k){ // 区间修改，O(logn)
  if(x<=tr[p].l&&tr[p].r<=y){ // 覆盖则直接修改
    tr[p].sum+=k*(tr[p].r-tr[p].l+1);
    tr[p].add+=k;
    return;
  }
  pushdown(p); // 不覆盖则下传懒标记，然后访问左右子树
  int m=tr[p].l+tr[p].r>>1;
  if(x<=m) update(lc,x,y,k);
  if(m<y) update(rc,x,y,k);
  pushup(p);
}

int query(int p,int x,int y){ // 区间查询，O(logn)
  if(x<=tr[p].l && tr[p].r<=y) return tr[p].sum;
  int m=tr[p].l+tr[p].r>>1;
  pushdown(p);
  int sum=0;
  if(x<=m) sum+=query(lc,x,y);
  if(m<y) sum+=query(rc,x,y);
  return tr[p].sum+sum;
}

int main(){
  int n,m; cin>>n>>m;
  for(int i=1;i<=n;i++) cin>>w[i];
  build(1,1,n);
  while(m--){
    int op,x,y;
    cin>>op>>x>>y;
    if(op) update(1,x,x,y);
    else cout<<query(1,x,y)<<'\n';
  }
  return 0;
}