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
vector<vector<int>> e;
bool vis[N];
VI ans;

void bfs(int u){
  queue<int>q;
  q.push(u);
  while(q.size()){
    u=q.front();
    q.pop();
    ans[u]=max(ans[u],u);
    for(auto v:e[u]){
      if(vis[v]) continue;
      vis[v]=true;
      q.push(v);
      ans[v]=max(ans[v],ans[u]);
    }
  }
}

void dfs(int u){
  for(auto v:e[u]){
    if(ans[v]) continue;
    ans[v]=ans[u];
    dfs(v);
  }
}

void solve(){
	cin>>n>>m;
  e.resize(n+1);
  ans.resize(n+1,0);
  for(int i=1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    e[b].push_back(a);
  }
  // for(int i=1;i<=n;++i){
  //   // memset(vis,0,sizeof vis);
  //   // bfs(i);
  // }
  for(int i=n;i>=1;i--){
    ans[i]=max(ans[i],i);
    dfs(i);
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