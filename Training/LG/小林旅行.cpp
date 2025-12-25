#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e9+9, mod = 998244353;

struct edge{int v,w;};

void bfs(vector<edge> e[],vector<int> paths[],vector<int> vis,int x){
  priority_queue<pair<int,int>> q;
  q.push({0,1});
  paths[1].push_back(1);
  while(q.size()){
    int u=q.top().second, ww=q.top().first;
    q.pop();
    if(vis[u]) continue;
    vis[u]=1;
    for(auto ed : e[u]){
      int v=ed.v, w=ed.w;
      q.push({ww-w,v});
      paths[v]=paths[u];
      paths[v].push_back(v);
      if(v==x){
        for(auto p : paths[x]) cout<<p<<' ';
        return;
      }
    }
  }
  cout<<"-1\n";
}

void qwq_(){
	int n,m,x;
	cin>>n>>m>>x;
  vector<int> vis(n+1,0);
  vector<int> paths[n+1];
  vector<edge> e[n+1];
	for(int i=1;i<=m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    e[u].push_back({v,w});
    e[v].push_back({u,w});
  }
  bfs(e,paths,vis,x);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}