#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
const int M = 1e5+9;

int n,m;
struct edge{int v,w,ne;};
edge e[M];        // 边集
int idx,h[N];     // 点的第一条出边

// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)

void add(int a,int b,int c){
  e[idx]={b,c,h[a]};
  h[a]=idx++;
}

void dfs(int u,int fa){
  for(int i=h[u];~i;i=e[i].ne){
    int v=e[i].v,w=e[i].w;
    if(v==fa) continue;
    printf("%d,%d,%d\n",u,v,w);
    dfs(v,u);
  }
}

void bfs(int u){
  
}

int main(){
  cin>>n>>m;
  memset(h,-1,sizeof h);
  for(int i=1;i<=m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    add(a,b,c);
    add(b,a,c);
  }

  dfs(1,0);
  // bfs(1,0);

  return 0;
}