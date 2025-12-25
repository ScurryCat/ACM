#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int INF = (1<<31)-1;
const int N = 1e5+9, mod = 998244353;

struct edge{int v,w;};
int n,m,s;
int d[N],vis[N];
vector<edge> e[N];
priority_queue<pair<int,int>> pq;

void Dijkstra(int s){
  for(int i=1;i<=n;i++) d[i]=INF;
  d[s]=0;
  pq.push({-d[s],s});
  while(pq.size()){
    int u=pq.top().second;
    pq.pop();
    if(vis[u]) continue;
    vis[u]=1;
    for(auto ed : e[u]){
      int v=ed.v, w=ed.w;
      if(d[u]+w<d[v]){
        d[v]=d[u]+w;
        pq.push({-d[v],v});
      }
    }
  }
}

void solve(){
  cin>>n>>m>>s;
  for(int i=1;i<=m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    e[u].push_back({v,w});
  }
  Dijkstra(s);
  for(int i=1;i<=n;i++) cout<<d[i]<<' ';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}