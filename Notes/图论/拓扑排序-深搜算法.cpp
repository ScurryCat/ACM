#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+9;

struct edge{
  int v,w;
};

int n,m;
int c[N];
vector<int> e[N];
vector<int> tp;

bool dfs(int u){
  c[u]=-1;
  for(auto v : e[u]){
    if(c[v]<0) return 0;  // 有环
    else if(!c[v]) 
      if(!dfs(v)) return 0;
  }
  c[u]=1;
  tp.push_back(u);
  return 1;
}

bool toposort(){
  memset(c,0,sizeof c);
  for(int i=1;i<=n;i++){
    if(!c[i]) 
      if(!dfs(i)) return 0;
  }
  reverse(tp.begin(),tp.end());
  return 1;
}

int main(){
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    int u,v;
    cin>>u>>v;
    e[u].push_back(v);
  }
  if(toposort()){
    for(auto x : tp){
      cout<<x<<' ';
    }
    cout<<'\n';
  }
  else cout<<"-1\n";
  return 0;
}