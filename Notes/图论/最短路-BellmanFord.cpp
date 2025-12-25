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
int d[N],vis[N],cnt[N],pre[N];
vector<edge> e[N];

int BellmanFord(int s){
  for(int i=1;i<=n;i++) d[i]=INF;
  d[s]=0;
  int flag; // 是否松弛
  for(int i=1;i<=n;i++){  // n轮
    flag = 0;
    for(int u=1;u<=n;u++){  // n点
      if(d[u]==INF) continue;
      for(auto ed : e[u]){
        int v=ed.v, w=ed.w;
        if(d[v]>d[u]+w){
          d[v]=d[u]+w;
          flag = 1;
        } 
      }
    }
    if(!flag) break; // 一轮下来无成功执行松弛操作，则所有点已找到最短路 
  }
  return flag;  // 第n轮==true则有环，负环 
}

bool SPFA(int s){
  for(int i=1;i<=n;i++) d[i]=INF;
  d[s]=0;
  queue<int> q;
  q.push(s);
  vis[s]=1;
  while(q.size()){
    bool flag=0;
    int u=q.front();
    q.pop();
    vis[u]=0;
    for(auto ed : e[u]){
      int v=ed.v,w=ed.w;
      if(d[v]>d[u]+w){
        d[v]=d[u]+w;
        cnt[v]=cnt[u]+1;    // 记录边数
        if(cnt[v]>=n) return true;  // 存在负环
        // if(++cnt[v]>=n) return true; // 可以直接计数松弛次数，如果>=n次,则必定有环
        if(!vis[v]) q.push(v),vis[v]=1;
      }
    }
  }
  return false;
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
  // BellmanFord(1);
  SPFA(1);
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