#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
const int N = 11;
int n,vis[N],ans[N];

// 时间复杂度O(n!)
void dfs(int m){
  if(m==n){
    for(int i=0;i<n;i++) printf("%5d",ans[i]);
    printf("\n");
    return;
  }
  for(int i=1;i<=n;i++){
    if(vis[i]) continue;
    vis[i]=1;
    ans[m]=i;
    dfs(m+1);
    vis[i]=0;
  }
}

int main(){
  scanf("%d",&n);
  dfs(0);
  return 0;
}