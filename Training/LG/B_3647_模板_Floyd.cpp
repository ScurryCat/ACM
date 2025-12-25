#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e2+9, mod = 998244353;

struct edge{int v,w;};
int n,m;
int d[N][N];
vector<edge> e[N];

void Floyd(){
  memset(d,0x3f,sizeof d);
  for(int u=1;u<=n;u++){
    for(auto ed:e[u]){
      int v=ed.v,w=ed.w;
      d[u][v]=min(d[u][v],w); // 处理重边
    }
    d[u][u]=0;
  }
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

void solve(){
	cin>>n>>m;
  for(int i=1;i<=m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    e[u].push_back({v,w});
    e[v].push_back({u,w});
  }
  Floyd();
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cout<<d[i][j]<<' ';
    }
    cout<<'\n';
  }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}