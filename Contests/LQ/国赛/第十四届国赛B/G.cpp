#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e3+9;

int n, m, k;
char g[N][N];
int vis[N][N], dis[N][N];

struct point{
  char ch;
  int x, y;
};

inline void bfs(int x, int y){
  memset(dis, 0x3f, sizeof dis);
  dis[x][y] = 0;

  queue<point> q;
  q.push({'A', x, y});

  while(q.size()){
    char t = q.front().ch;
    x = q.front().x;
    y = q.front().y;

    dfs('A',)
  }

}

inline void solve(){
  cin >> n >> m >> k;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      cin >> g[i][j];
    }
  }

  bfs(1, 1);

  cout << dis[n][m];
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t = 1;
  // cin >> t;
  while(t--){
    solve();
  }

  return 0;
}