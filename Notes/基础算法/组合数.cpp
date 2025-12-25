#include <bits/stdc++.h>
using namespace std;

const int N = 26;
int n,m,vis[N],ans[N];

void dfs(int s,int k){
  if(k==m){
    for(int i=0;i<m;i++) printf("%-3d",ans[i]);
    printf("\n");
    return ;
  }
  for(int i=s;i<=n;i++){
    if(vis[i]) continue;
    vis[i] = 1;
    ans[k] = i;
    dfs(i+1,k+1);
    vis[i] = 0;
  }
}

int main(){
  scanf("%d %d",&n,&m);
  dfs(1,0);
  return 0;
}