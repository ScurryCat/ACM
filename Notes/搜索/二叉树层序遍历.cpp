#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;

int n,tree[N];

void bfs(int s){
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int x=q.front();
    q.pop();
    cout<<tree[x]<<' ';
    if(x+x<=n) q.push(x+x);
    if(x+x+1<=n) q.push(x+x+1);
  }
}

int main(){
  cin>>n;
  for(int i=1;i<=(1<<n)-1;i++) tree[i]=i;

  bfs(1);

  return 0;
}