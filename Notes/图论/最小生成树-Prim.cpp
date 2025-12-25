#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int INF = (1<<31)-1;
const int N = 1e5+9, mod = 998244353;

struct edge{int v,w;};
int n,m;
int ans,cnt;
int d[N], vis[N];
priority_queue<pair<int,int>> q;
vector<edge> e[N];
vector<char> conect;

bool prim(int s){
  memset(d,0x3f,sizeof d);
  d[s]=0;
  q.push({0,s});
  while(q.size()){
    int u=q.top().second;
    q.pop();
    if(vis[u]) continue;
    vis[u]=1;
    conect.push_back(char(u));
    for(auto p : conect) cout<<p<<' ';cout<<'\n';
    ans+=d[u]; cnt++;
    for(auto ed : e[u]){
      int v=ed.v, w=ed.w;
      if(d[v]>w){
        d[v]=w;
        q.push({-d[v],v});
      }
    }
  }
  return cnt==n;
}

void solve(){
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    char u,v;
    int w;
    cin>>u>>v>>w;
    // cout<<u<<' '<<v<<' '<<w<<'\n';
    e[u].push_back({v,w});
    e[v].push_back({u,w});
  }

  char s='a';
  prim(s);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}