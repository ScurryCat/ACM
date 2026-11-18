#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6+9;

ll l, r, k;
int vis[N], pri[N], idx;
ll p[N], tot;

inline void ora(int x){
  for(int i=2; i<=x; i++){
    if(!vis[i]) pri[++idx] = i;
    for(int j=1; i * pri[j]<=x; j++){
      vis[i * pri[j]] = 1;
      if(i % pri[j] == 0) break;
    }
  }
}

inline bool check(ll x){
  int n = 0;
  while(x){
    n += x % 10;
    x /= 10;
  }
  int a = 0, b = 1000, m;
  while(a + 1 < b){
    m = a + b >> 1;
    if(m * m == n) break;
    else if(m * m < n) a = m;
    else b = m;
  }
  return m * m == n;
}

inline void solve(){
  cin >> l >> r >> k;
  ora(sqrt(r) + 1);
  memset(vis, 0, sizeof vis);
  if(l == 1) vis[1] = 1;
  for(int i=1; i<=idx; i++){
    ll st = max(1ll * pri[i] * pri[i], ((l + pri[i] - 1) / pri[i]) * pri[i]);
    for(ll j = st; j<=r; j+=pri[i]){
      vis[j - l + 1] = 1;
    }
  }
  for(ll i=l; i<=r; i++){
    if(!vis[i - l + 1]) p[++tot] = i;
  }

  ll cnt = 0;
  for(int i=1; i<=tot; i++){
    if(check(p[i])) cnt++;
    if(cnt == k){
      cout << p[i];
      return;
    }
  }
  cout << -1;
}

int main(){

  solve();

  return 0;
}