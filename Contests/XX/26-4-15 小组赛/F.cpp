#include <bits/stdc++.h>
using namespace std;

using ll = long long; using ld = double;

int n, m;
int mp[109][109];
ll f[109][109];
int vis[109][109];

int dx[] = {-3, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 3};
int dy[] = {0, 1, -1, 2, -2, 3, -3, 2, -2, 1, -1, 0};

inline void ac(){
  cin >> n >> m;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin >> mp[i][j];

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      f[i][j] = 1ll << 62;
    }
  }
  f[1][1] = 0;
  //dfs(1, 1);

  // queue<pair<int,int> > q;
  priority_queue<pair<ll, pair<int, int> > > q;
  q.push({0,{1,1}});

  while(q.size()){
    // int x=q.front().first, y=q.front().second;
    int x=q.top().second.first, y=q.top().second.second;
    q.pop();
    if(vis[x][y]) continue;
    vis[x][y] = 1;
    for(int i=0;i<12;i++){
      int nx = x+dx[i], ny = y+dy[i];
      if(nx<1 || ny<1 || nx>n || ny>n) continue;
      if(vis[nx][ny]) continue;
      if(f[nx][ny] > f[x][y] + mp[nx][ny] + 3 * m){
        f[nx][ny] = f[x][y] + mp[nx][ny] + 3 * m;
        q.push({-f[nx][ny],{nx,ny}});
      }
    }
  }

  // for(int i=1;i<=n;i++){
  //   for(int j=1;j<=n;j++){
  //     cout << f[i][j]<<' ';
  //   }
  //   cout << '\n';
  // }

  ll res = f[n][n];
  res = min(res, f[n-2][n] + 2 * m);
  res = min(res, f[n-1][n-1] + 2 * m);
  res = min(res, f[n-1][n] + m);
  res = min(res, f[n][n-1] + m);
  res = min(res, f[n][n-2] + 2 * m);
  cout << res;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  #ifdef LOCAL
  freopen("F.in", "r", stdin);
  // freopen("gen.out", "r", stdin);
  #endif // LOCAL

  int t = 1;
  // cin >> t;
  while(t--) ac();
  return 0;
}