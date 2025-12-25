#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+9;

struct edge{
  int v,w;
};

int n,m;
int din[N];
vector<int> e[N];
vector<int> tp;

bool toposort(){
  queue<int> q;
  for(int i=1;i<=n;i++){
    if(!din[i]){
      q.push(i);
    }
  }
  while(q.size()){
    int u=q.front();  q.pop();
    tp.push_back(u);
    for(auto v : e[u]){
      if(--din[v]==0){
        q.push(v);
      }
    }
  }
  return tp.size()==n;
}

int main(){
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    int u,v;
    cin>>u>>v;
    e[u].push_back(v);
    din[v]++;
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