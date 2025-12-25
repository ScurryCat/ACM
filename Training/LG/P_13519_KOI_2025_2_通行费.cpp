#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e2+9, mod = 998244353;

struct edge{int u,v;};
int n,m;
int d[N][N];
vector<edge> e;

void Floyd(){
  
}

void solve(){
  memset(d,0x3f,sizeof d);
	cin>>n>>m;
  for(int i=1;i<=m;i++){
    int u,v;
    cin>>u>>v;
    d[u][v]=1;
    e.push_back({u,v});
  }
  for(int i=1;i<=n;i++) d[i][i]=0;
  Floyd();
  for(int i=1;i<=n;i++){
    int ans=0;
    for(int j=1;j<=n;j++){
      if(d[i][j]!=0x3f3f3f3f){
        ans+=d[i][j];
      }
    }
    cout<<ans<<'\n';
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