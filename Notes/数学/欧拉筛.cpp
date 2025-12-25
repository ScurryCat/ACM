#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e9+9;
const int M = 1e5+9;
ll pri[M],cnt;
bool vis[N];

void Ora(int n){
  for(ll i=2;i<=n;i++){
    if(!vis[i]) pri[++cnt] = i;
    for(ll j=1;i*pri[j]<=n;j++){
      vis[i*pri[j]] = true;         // 合数被筛掉
      if(i%pri[j]==0) break;        // 保证每个合数都是被它的最小质因子筛掉,避免重复筛。  比如12被2筛掉就不会再被3筛了
    }
  }
}

int main(){  
  ll n; cin>>n;
  Ora(n);
  for(ll i=1;i<=cnt;i++) cout<<pri[i]<<' ';
  return 0;
}