#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int n,m;
int vis[N];
vector<int> e[N];

void dfs(int u){
  if(vis[u]) return;
  vis[u]=1;
  cout<<u<<' ';
  for(auto v : e[u]){
    if(vis[v]) continue;
    dfs(v);
  }
}

void bfs(int u){
  memset(vis,0,sizeof vis);
  queue<int> q;
  vis[u]=1;
  q.push(u);
  while(q.size()){
    u=q.front();
    q.pop();
    cout<<u<<' ';
    for(auto v : e[u]){
      if(vis[v]) continue;
      vis[v]=1;
      q.push(v);
    }
  }
}

void qwq_(){
	cin>>n>>m;
  for(int i=1;i<=m;i++){
    int u,v;
    cin>>u>>v;
    e[u].push_back(v);
  }
  for(int i=1;i<=n;i++) sort(e[i].begin(),e[i].end());
  dfs(1);
  cout<<'\n';
  bfs(1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}