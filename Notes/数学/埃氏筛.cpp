#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e9+9;
const int M = 1e5+9;
ll pri[M],cnt;
bool vis[N];

void Eratosthenes(int n){
  for(ll i=2;i<=n;i++){
    if(!vis[i]){
      pri[++cnt] = i;
      for(ll j=i*i;j<=n;j+=i) vis[j]=true;
    }
  }
}

int main(){
  ll n; cin>>n;
  Eratosthenes(n);
  for(ll i=1;i<=cnt;i++) cout<<pri[i]<<' ';
  return 0;
}