#include <bits/stdc++.h>
using namespace std;

int Phi(int n){                   // 试除法求欧拉函数
  int r = n;
  for(int i=2;i*i<=n;i++){
    if(n%i==0){
      r = r * (i-1) / i;
      while(n%i==0) n /= i;
    }
  }
  if(n>1) r = r * (n-1) / n;
  return r;
}

const int N = 1e6+9;
int pri[N],phi[N],cnt;
bool vis[N];

void get_phi(int n){                        // 线性筛求欧拉函数
  for(int i=2;i<=n;i++){
    if(!vis[i]){
      pri[++cnt] = i;
      phi[i] = i-1;                         // 若i为质数，则phi[i]=i-1
    }
      for(int j=1;i*pri[j]<=n;j++){
      int m = i * pri[j];
      vis[m] = true;
      if(i % pri[j] == 0){
        phi[m] = pri[j] * phi[i];           // pri[j]是m的最小质因子 用已解出的phi[i]来递推为止的phi[m]
        break;
      }
      else phi[m] = phi[i] * phi[pri[j]];   // i 与 pri[j] 互质，则利用积性函数性质得：phi[i] = phi[i] * phi[pri[j]]
    }
  }
}

int main(){
  int n;  cin>>n;
  // cout<<Phi(n)<<'\n';
  get_phi(n);
  for(int i=1;i<=n;i++){
    cout<<i<<' '<<phi[i]<<'\n';
  }
  return 0;
}