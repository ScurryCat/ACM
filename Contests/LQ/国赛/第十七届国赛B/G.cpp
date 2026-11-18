#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 3e5+9, mod = 998244353;

int n, m;
int a[N];
ll s[N];

inline int lowbit(int x){
  return x & -x;
}

inline ll qpow(ll a){
  ll r = 1, b = mod - 2;
  while(b){
    if(b & 1) r = r * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return r;
}

inline void change(int x, ll k){
  while(x <= n){
    s[x] += k;
    x += lowbit(x);
  }
}

inline ll query(int x){
  ll r = 0;
  while(x >= 1){
    r += s[x];
    r %= mod;
    x -= lowbit(x);
  }
  return r;
}

inline void solve(){
  cin >> n >> m;
  for(int i=1; i<=n; i++){
    cin >> a[i];
    change(i, a[i]);
  }
  for(int i=1; i<=m; i++){
    ll op, x, y;
    cin >> op >> x >> y;
    if(op == 1){
      ll aver = qpow(y - x + 1) * (query(y) - query(x - 1) + mod) % mod;
      ll var = 0;
      for(int j=x; j<=y; j++){
        var = (var + ((a[j] - aver) * (a[j] - aver))) % mod;
      }
      cout << aver << ' ' << var << '\n';
    }
    else if(op == 2){
      change(x, -a[x]);
      a[x] = y;
      change(x, a[x]);
    }
  }
}

int main(){

  solve();

  return 0;
}