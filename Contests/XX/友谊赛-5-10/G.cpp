#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 19683, INF = 1e9;

int mem[N], vis[N];
int p[10];

inline double find(double l, double r){
  if(l < 0 && r > 0) return 0;
  if(l <= -INF / 2){
    double z = 0;
    while(z >= r) z -= 1;
    return z;
  }
  if(r >= INF / 2){
    double z = 0;
    while(z <= l) z += 1;
    return z;
  }

}

inline int lowbit(int x){
  return x & -x;
}

inline void dfs(int n){
  if(n < 0 || n > N) return;
  if(vis[n]) return;

  int f[10];
  for(int i=1; i<=9; i++){
    f[i] = n % 3;
    n /= 3;
  }

  for(int i=1; i<=9; i++){
    if(f[i] == 1){
      dfs(n - p[i-1]);
      dfs(n - p[i-1])
    }
    else if(f[i] == 2){
      dfs(n - 2 * p[i-1]);
    }
  }
}

inline void fun(int n){
  int f[10];
  cout << n << '\n';
  for(int i=1; i<=9; i++){
    f[i] = n % 3;
    n /= 3;
  }
  for(int i=1; i<=9; i++){
    cout << f[i];
    if(i == 3 || i == 6) cout << '\n';
  }
  cout << '\n';
}

inline void solve(){
  for(int i=0; i<10; i++){
    p[i] = pow(3, i);
  }

  fun(6 - 2 * p[2-1]);
  fun(N-1);
  fun(N-1 - 2 * p[4]);

  // for(int i=0; i<N; i++){
  //   if(vis[i]) continue;
  //   dfs(i);
  // }

}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }

  return 0;
}