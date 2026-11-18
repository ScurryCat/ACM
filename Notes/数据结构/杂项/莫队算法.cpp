#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6+9;

int B;

struct Q{
  int l, r, id;
  bool operator<(const Q &q) const{
    if(l / B != q.l / B) return l < q.l;
    if((l / B) & 1) return r < q.r;
    else return r > q.r;
  }
}q[N];

int n, m, k, l = 1, r;
int a[N];
ll sum, c[N], ans[N];

void add(int x){
  sum -= c[x] * c[x];
  c[x]++;
  sum += c[x] * c[x];
}

void del(int x){
  sum -= c[x] * c[x];
  c[x]--;
  sum += c[x] * c[x];
}

void solve(){
  cin >> n >> m >> k;
  B = sqrt(n);
  for(int i=1; i<=n; i++) cin >> a[i];
  for(int i=1; i<=m; i++) cin >> q[i].l >> q[i].r, q[i].id = i;
  sort(q+1, q+m+1);
  for(int i=1; i<=m; i++){
    while(l > q[i].l) add(a[--l]);  // 先移动再增加
    while(r < q[i].r) add(a[++r]);
    while(l < q[i].l) del(a[l++]);  // 先删除再移动
    while(r > q[i].r) del(a[r--]);
    ans[q[i].id] = sum;
  }
  for(int i=1; i<=m; i++) cout << ans[i] << '\n';
}

int main(){
  solve();
  return 0;
}