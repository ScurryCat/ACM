#include <bits/stdc++.h>
using namespace std;

int n,ans;	// n 点数， ans 最大权值
int w[25];	// w[i] i点的权值
int m[25][25];	// m[i][j] i是否可以通往j  若为1则可以，若为0则不行

vector<int> path,cp;	// path 答案路径  cp 暂存当前路径

void dfs(int u,int ww){
  if(ans<ww){
    ans=ww;
    path=cp;
  }
  for(int v=u+1;v<=n;v++){
    if(m[u][v]){
      cp.push_back(v);
      dfs(v,ww+w[v]);
      cp.pop_back();
    }
  }
}

void solve(){
  cin>>n;
  for(int i=1;i<=n;i++) cin>>w[i];

  for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
      cin>>m[i][j];

  for(int i=1;i<=n;i++) m[0][i]=1;
  dfs(0,0);

  for(auto x : path) cout<<x<<' ';
  cout<<'\n';
  cout<<ans;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int qaq=1;// cin>>qaq;
  while(qaq--) solve();
  return 0;
}

