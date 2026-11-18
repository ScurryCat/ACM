#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+9;

int lowbit(int x){
  return x & -x;
}

int n, q;
int a[N], s[N];

void change(int x, int k){
  while(x <= n) s[x] += k, x += lowbit(x);
}

int query(int x){
  int r = 0;
  while(x >= 1) r += s[x], x -= lowbit(x);
  return r;
}

void solve(){
  cin >> n >> q;
  for(int i=1; i<=n; i++){
    cin >> a[i];
    change(i, a[i]);
  }
  while(q--){
    int op, x, y;
    cin >> op >> x >> y;
    if(op == 1){
      change(x, y);
    }
    else if(op == 2){
      cout << query(y) - query(x - 1) << '\n';
    }
  }
}

int main(){
  solve();
  return 0;
}