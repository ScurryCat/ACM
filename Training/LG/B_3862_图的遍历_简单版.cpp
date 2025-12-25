#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m;
int ans[N];
bool vis[N];
VI e[N];

void bfs(int u){
  queue<int> q;
  q.push(u);
  memset(vis,0,sizeof vis);
  while(q.size()){
    u=q.front();
    q.pop();
    if(vis[u]) continue;
    vis[u]=true;
    for(auto v:e[u]){
      ans[u]=max(ans[u],v);
      q.push(v);
    }
  }
}

int dfs(int u){
  if(vis[u]) return ans[u];
  vis[u]=true;
  ans[u]=u;
  for(int v:e[u]){
    ans[u]=max(ans[u],dfs(v));
  }
  return ans[u];
}

void solve(){
	cin>>n>>m;
  for(int i=1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    e[a].push_back(b);
  }
  for(int i=n;i>=1;i--){
    // memset(vis,0,sizeof vis);     // 为什么这一行放在循环内部就可以AC？    // 实际上是没有这行的话从小点到大点就无法再返回小点了，因此若小点有多个指向，大点只能获取小点仍在计算中的ans,而不是计算到最后正确的ans，会少遍历许多可能的分支，若要解决这个问题，从大点开始执行循环或许可行？  // 实测不可行，不知道具体是小点调大点还是大点调小点，因此只能集体标记为未访问
    // bfs(i);
    dfs(i)<<' ';
  }
  for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int T = 1;
    // cin>>T;
    while(T--) solve();
    return 0;
}