#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+9;

// 文艺平衡树，用于维护一个支持区间反转的有序数列
struct node{
  int p, s[2], v, size, tag;
  void init(int pp, int vv){
    p = pp; v = vv; size = 1;
  } 
}tr[N];
int root, idx;
int n, m;

inline void pushup(int x){
  tr[x].size = tr[tr[x].s[0]].size + tr[tr[x].s[1]].size + 1;
}

inline void pushdown(int x){ // 下传
  if(tr[x].tag){
    swap(tr[x].s[0], tr[x].s[1]);
    tr[tr[x].s[0]].tag ^= 1;
    tr[tr[x].s[1]].tag ^= 1;
    tr[x].tag = 0;
  }
}

inline void rotate(int x){
  int y = tr[x].p, z = tr[y].p;
  int k = (tr[y].s[1] == x);
  tr[y].s[k] = tr[x].s[k^1];
  tr[tr[x].s[k^1]].p = y;
  tr[x].s[k^1] = y;
  tr[y].p = x;
  tr[z].s[tr[z].s[1] == y] = x;
  tr[x].p = z;
  pushup(y); pushup(x);
}

inline void splay(int x, int k){
  while(tr[x].p != k){
    int y = tr[x].p, z = tr[y].p;
    if(z != k){
      (tr[y].s[0]==x) ^ (tr[z].s[0]==y) ? rotate(x) : rotate(y);
    }
    rotate(x);
  }
  if(k == 0) root = x;
}

inline void insert(int v){
  int x = root, p = 0;
  while(x){
    p = x;
    x = tr[x].s[v > tr[x].v];
  }
  x = ++idx;
  tr[p].s[v > tr[p].v] = x;
  tr[x].init(p, v);
  splay(x, 0);
}

inline int get_k(int k){ // 返回第k个节点的编号
  int x = root;
  while(1){
    pushdown(x);
    int y = tr[x].s[0];
    if(tr[y].size + 1 < k){
      k -= tr[y].size + 1;
      x = tr[x].s[1];
    }
    else{
      if(tr[y].size >= k) x = y;
      else break;
    }
  }
  splay(x, 0);
  return x;
}

inline void output(int x){
  pushdown(x);
  if(tr[x].s[0]) output(tr[x].s[0]);
  if(1 <= tr[x].v && tr[x].v <= n) cout << tr[x].v << ' ';
  if(tr[x].s[1]) output(tr[x].s[1]);

}

int main(){
  insert(-1e9), insert(1e9);
  cin >> n >> m;
  for(int i=1; i<=n; i++) insert(i);
  while(m--){
    int l, r;
    cin >> l >> r;
    // 将[l, r]夹到l-1, r+1中间
    l = get_k(l);
    r = get_k(r+2);
    splay(l, 0);
    splay(r, l);
    tr[tr[r].s[0]].tag ^= 1;
  }
  output(root);
  return 0;
}