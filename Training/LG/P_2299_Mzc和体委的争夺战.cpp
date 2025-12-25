#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const ll INF = (1ll<<48)-1;
const int N = 3e3+9, mod = 998244353;

struct edge{int v,w;};
int n,m;
ll d[N],vis[N];
vector<edge> e[N];

// 注意本题是无向图，可能有环，不能用dijk
void Dijkstra(int s){
  for(int i=0;i<=n;i++) d[i]=INF;
  d[s]=0;
  for(int i=1;i<n;i++){
    int u=0;
    for(int j=1;j<=n;j++){
      if(!vis[j]&&d[u]>d[j]) u=j;
    }
    vis[u]=1;
    for(auto ed : e[u]){
      int v=ed.v, w=ed.w;
      if(d[u]+w<d[v]) d[v]=d[u]+w;
    }
  }
}

void solve(){
	cin>>n>>m;
  for(int i=1;i<=m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    e[u].push_back({v,w});
    e[v].push_back({u,w});
  }
  Dijkstra(1);
  cout<<d[n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}