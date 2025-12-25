#include <bits/stdc++.h>
using namespace std;

const int N = 30;

int n,ans=0;
int w[N],dp[N],vis[N];
vector<int> e[N],tp,p,cp;

void dfs(int u,int ww){
  if(ans<ww){
    ans=ww;
    p=cp;
  }
  for(auto v : e[u]){
    if(vis[v]) continue;
    cp.push_back(v);
    vis[v]=1;
    dfs(v,ww+w[v]);
    cp.pop_back();
    vis[v]=0;
  }
}

void solve(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>w[i];
    dp[i]=w[i];
  }

  for(int u=1;u<=n;u++){
    for(int v=u+1;v<=n;v++){
      int x; cin>>x;
      if(x) e[u].push_back(v);
    }
  }
  for(int i=1;i<=n;i++){
    cp.push_back(i);
    dfs(i,w[i]);
    cp.pop_back();
  }
  for(auto x : p) cout<<x<<' ';
  cout<<'\n';
  cout<<ans;
}

int main(){
  ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

  int qaq=1;
  // cin>>qaq;
  while(qaq--) solve();
  return 0;
}