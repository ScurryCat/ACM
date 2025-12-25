#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int INF = (1<<31)-1;
const int N = 1e5+9, mod = 998244353;

struct edge{int v,w;};
int n,m;
int d[N],vis[N];
vector<edge> e[N];

// 注意本题w可能取负，不能用dijk
void Dijkstra(int s){
  for(int i=0;i<=n;i++) d[i]=-1;
  d[s]=0;
  for(int i=1;i<n;i++){
    int u=0;
    for(int j=1;j<=n;j++){
      if(!vis[j]&&d[j]>d[u]) u=j;
    }
    vis[u]=1;
    for(auto ed : e[u]){
      int v=ed.v, w=ed.w;
      if(d[v]<d[u]+w) d[v]=d[u]+w;
    }
  }
}

void BellmanFord(int s){
  for(int i=1;i<=n;i++) d[i]=INF;
  d[s]=0;
  int flag;
  for(int i=1;i<=n;i++){
    flag=1;
    for(int u=1;u<=n;u++){
      if(d[u] == INF) continue;
      for(auto ed : e[u]){
        int v=ed.v,w=ed.w;
        if(d[v]>d[u]+w){
          d[v]=d[u]+w;
          flag=0;
        }
      }
    }
    if(flag) break;
  }
}

void solve(){
	cin>>n>>m;
  for(int i=1;i<=m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    e[u].push_back({v,-w});
  }
  // Dijkstra(1);
  BellmanFord(1);
  if(d[n]==INF) cout<<-1;
  else cout<<-d[n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}