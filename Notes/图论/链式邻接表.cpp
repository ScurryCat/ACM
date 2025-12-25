#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
const int M = 1e5+9;

int n,m;
struct edge{int u,v,w;};
vector<edge> e;     // 边集
vector<int> h[N];   // 表头,储存点的所有出边

// 时间复杂度O(n+m)
// 空间复杂度O(n+m)

void add(int a,int b,int c){
  e.push_back({a,b,c});
  h[a].push_back(e.size()-1);
}

void dfs(int u,int fa){
 for(int i=0;i<h[u].size();i++){
  int j=h[u][i];
  int v=e[j].v,w=e[j].w;
  if(v==fa) continue;
  printf("%d,%d,%d\n",u,v,w);
  dfs(v,u);
 }
}

struct ufa{int u,fa;};
void bfs(int u,int fa){
  queue<ufa> q;
  q.push({u,fa});
  while(!q.empty()){
    u=q.front().u,fa=q.front().fa;
    q.pop();
    for(int i=0;i<h[u].size();i++){
      int j=h[u][i];
      int v=e[j].v,w=e[j].w;
      if(v==fa) continue;
      printf("%d,%d,%d\n",u,v,w);
      q.push({v,u});
    }
  }
}

int main(){
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    add(a,b,c);
    add(b,a,c);
  }

  // dfs(1,0);
  bfs(1,0);
  return 0;
}