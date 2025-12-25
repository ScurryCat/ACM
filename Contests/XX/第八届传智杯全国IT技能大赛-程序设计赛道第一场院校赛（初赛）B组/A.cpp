#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 6300, inf = 0x3f3f3f3f;

struct edge{int v,w;};

int n,m,s,t;
int vis[N];
vector<edge> e[N];

void dijkstra(){
  vector<ll> d(n+1,inf);
  d[s]=0;
  priority_queue<pair<ll,int>> q;
  q.push({-d[s],s});
  while(q.size()){
    int u=q.top().second;
    q.pop();
    if(vis[u]) continue;
    vis[u]=1;
    for(auto ed:e[u]){
      int v=ed.v, w=ed.w;
      if(d[u]+w<d[v]){
        d[v]=d[u]+w;
        q.push({-d[v],v});
      }
    }
  }
  cout<<d[t];
}

int main(){
  cin>>n>>m>>s>>t;
  for(int i=1;i<=m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    e[u].push_back({v,w});
    e[v].push_back({u,w});
  }
  dijkstra();
	return 0;
}