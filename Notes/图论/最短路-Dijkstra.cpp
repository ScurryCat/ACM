#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int INF = (1<<31)-1;
const int N = 1e5+9, mod = 998244353;

/*
  priority_queue<pair<long long,int>> pq; // 大根堆
  dist[s] = 0;
  pq.push({-dist[s], s});                 // 注意取负

  while(!pq.empty()){
      auto [negd, u] = pq.top(); pq.pop();
      long long d = -negd;                // 还原
      if(d != dist[u]) continue;          // 丢弃陈旧条目
      for(auto [v, w] : adj[u]){
          if(dist[v] > d + w){
              dist[v] = d + w;
              pq.push({-dist[v], v});     // 继续取负
          }
      }
  }

  */

/*
  priority_queue<
      pair<long long,int>,
      vector<pair<long long,int>>,
      greater<pair<long long,int>>        // 由于需要写比较器，所以不能跳过第二个参数，必须手动补全
  > pq;                                   // 最小堆
  dist[s] = 0;
  pq.push({dist[s], s});

  while(!pq.empty()){
      auto [d, u] = pq.top(); pq.pop();
      if(d != dist[u]) continue;
      for(auto [v, w] : adj[u]){
          if(dist[v] > d + w){
              dist[v] = d + w;
              pq.push({dist[v], v});
          }
      }
  }
  */

// 小根堆写法，三个参数
//priority_queue<PII,vector<PII>,greater<PII>> pq;

// 大根堆写法，只需一个参数
priority_queue<pair<int,int>> pq;

struct edge{int v,w;};
int n,m,s;
int d[N],vis[N],pre[N];
vector<edge> e[N];

void Dijkstra(int s){
  for(int i=1;i<=n;i++) d[i]=INF;
  d[s]=0;
  pq.push({-d[s],s});
  while(pq.size()){
    int u=pq.top().second;
    pq.pop();
    if(vis[u]) continue;
    vis[u]=1;   // 标记第一次出队
    for(auto ed : e[u]){
      int v=ed.v, w=ed.w;
      if(d[u]+w<d[v]){
        d[v]=d[u]+w;
        pre[v]=u;
        pq.push({-d[v],v});
        // vis[v]=0;    // 试图通过修改标签反复出队，但这样的做法不能保证Dijkstra的时间复杂度，同时也会和SPFA算法一样被卡
      }
    }
  }
}

void path(int u){
  if(u==s) {cout<<u<<' ';return;}
  path(pre[u]);
  cout<<u<<' ';
}

void solve(){
  cin>>n>>m>>s;
  for(int i=1;i<=m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    e[u].push_back({v,w});
  }
  Dijkstra(s);
  for(int i=1;i<=n;i++){
    cout<<d[i]<<' ';
    // path(i);
    // cout<<'\n';
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