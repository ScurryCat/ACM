#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+9;

int n, m;
int ans;
struct edge{
  int u, v, w;
  bool operator<(const edge &e)const{
    return w < e.w;
  }
}e[N];

struct Kruskal{
  int find(vector<int> &fa, int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa, fa[x]);
  }

  bool kruskal(const int n, const int m, edge *e, int &ans){
    int cnt = 0;
    vector<int> fa(n+1);
    for(int i=1; i<=n; i++) fa[i] = i;
    sort(e, e+m);
    for(int i=0; i<m; i++){
      int x = find(fa, e[i].u);
      int y = find(fa, e[i].v);
      if(x != y){
        fa[x] = y;
        ans += e[i].w;
        cnt++;
      }
    }
    return cnt == n-1;
  }
};

int main(){
  Kruskal solve;
  cin >> n >> m;
  for(int i=0; i<m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    e[i] = {u, v, w};
  }
  if(solve.kruskal(n, m, e, ans)) cout << ans << '\n';
  else cout << "-1\n";
  return 0;
}