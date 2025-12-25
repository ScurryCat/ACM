#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m,n;
	cin>>n>>m;
  vector<ll> l,r;
  for(int i=0;i<n;i++){
    ll x; cin>>x;
    if(x<0) l.push_back(-x); else r.push_back(x);
  }
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  ll ans = LLONG_MAX;
  for(int k=0;k<=m;k++){
    int L=k;
    int R=m-k;
    if(L>(int)l.size()||R>(int)r.size()) continue;
    ll Ld=(L==0?0:l[L-1]);
    ll Rd=(R==0?0:r[R-1]);
    ll cur;
    if(L==0) cur=Rd;
    else if(R==0) cur=Ld;
    else cur=min(2*Ld+Rd,Ld+2*Rd);
    ans=min(ans,cur);
  }
  cout<<ans<<"\n";
  return 0;
}