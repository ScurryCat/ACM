#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll n){
  for(ll i=2;i*i<=n;i++){
    if(n%i==0) return 0;
  }
  return 1;
}

int main(){
  ll n;
  cin>>n;
  if(check(n)){
    cout<<"YES\n";
    cout<<qpow(1228590165,n-2,n);
  }
  else cout<<"NO\n";
}