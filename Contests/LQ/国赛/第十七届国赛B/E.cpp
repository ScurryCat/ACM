#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6+9;

int n, m;
string s;
int B;
int l, r = -1;
ll cnt;
ll ans[N];

struct Q{
  int l, r, id;
  bool operator<(const Q &q)const{
    if(l / B != q.l / B) return l < q.l;
    if((l / B) & 1) return r < q.r;
    return r > q.r;
  }
}q[N];

inline void add(int x){
  for(int i=n-1; ~i; i--){
    int y = x, j = i;
    while(s[j] - '0' == y % 10){
      j--; y /= 10;
      if(!y) cnt++;
    }
    if(!y){
      while(~j && s[j--] == '0') cnt++;
    }
  }
}

inline void del(int x){
  for(int i=n-1; ~i; i--){
    int y = x, j = i;
    while(s[j] - '0' == y % 10){
      j--; y /= 10;
      if(!y) cnt--;
    }
    if(!y){
      while(~j && s[j--] == '0') cnt--;
    }
  }
}

inline void solve(){
  cin >> n >> m >> s;
  B = sqrt(n);
  for(int i=1; i<=m; i++){
    cin >> q[i].l >> q[i].r;
    q[i].id = i;
  }
  sort(q+1, q+m+1);
  for(int i=1; i<=m; i++){
    while(l > q[i].l) add(--l);
    while(r < q[i].r) add(++r);
    while(l < q[i].l) del(l++);
    while(r > q[i].r) del(r--);
    ans[q[i].id] = cnt;
  }
  for(int i=1; i<=m; i++) cout << ans[i] << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();

  return 0;
}