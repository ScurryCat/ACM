#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_prime(int p){
  for(int i=2;i*i<=p;i++) if(p%i==0) return false;
  return true;
}

int qpow(ll a,int b,int p){
  int r = 1;
  while(b){
    if(b&1) r = (r * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return r;
}

int fun(int a,int p){
  if(is_prime(p)){                        // p是质数
    return qpow(a,p-2,p);       // 由费马小定理，p是质数，那么a^p-2就是a的逆元
  }
  if(a%p!=1) return -1;
  for(int i=1;i<p;i++){
    if((a*i)%p==1) return i;
  }
}

int main(){
  int n,p;
  cin>>n>>p;
  // cout<<fun(n,p);
  for(int i=1;i<=n;i++){
    cout<<fun(i,p)<<'\n';
  }
  return 0;
}