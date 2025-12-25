#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long ll;

const int N = 5e4+9, M = 1e6+9;

ll pri[N],idx;
bool vis[M];

void ora(int n){
  for(int i=2;i<=n;i++){
    if(!vis[i]) pri[++idx]=i;
    for(int j=1;i*pri[j]<=n;j++){
      vis[i*pri[j]]=1;
      if(i%pri[j]==0) break;
    }
  }
}

int main(){
  int l,r;
  scanf("%d%d",&l,&r);
  ora(sqrt(r));
  int s=1;
  while(pri[s]*pri[s]<l) s++;
  memset(vis,0,sizeof vis);
  for(int i=s;i<=idx;i++){
    for(int j=s;j<=idx;j++){
      vis[pri[i]*pri[j]-l+1]=1;
      if(pri[i]*pri[j]>r) break;
    }
  }
  int ans=0;
  for(int i=1;i<=r-l;i++) if(!vis[i]) ans++;
  printf("%d\n",ans);
  // for(int i=1;i<=idx;i++) printf("%d ",pri[i]);
  return 0;
}