#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;

ll x,y,a,b,n;
struct Matrix{
  ll m[2][2];
  Matrix(){memset(m,0,sizeof m);}
}res,tr;

Matrix operator*(Matrix a,Matrix b){
  Matrix r;
  for(int i=0;i<2;i++)
    for(int k=0;k<2;k++)
      for(int j=0;j<2;j++)
        r.m[i][j] = (r.m[i][j]+a.m[i][k]*b.m[k][j]) % mod;
  return r;
}

ll qpow(ll k){
  while(k){
    if(k&1) res = res * tr;
    tr = tr * tr;
    k >>= 1;
  }
  return res.m[0][0];
}

// 4 5 6
// 3 1 0
// 3 4 38 214 

/*
  A 行 * B 列
   A     B
  4 3   5 1
  0 0   6 0

  4 0   5 6
  3 0   1 0
*/

void solve(){
  scanf("%lld%lld%lld%lld%lld",&x,&y,&a,&b,&n);
  res.m[1][0]=res.m[1][1]=tr.m[1][1]=0;
  res.m[0][0]=y;
  res.m[0][1]=x;
  tr.m[0][0]=a;
  tr.m[0][1]=1;
  tr.m[1][0]=b;
  // res=res*tr;
  // cout<<res.m[0][0]<<' '<<res.m[0][1]<<'\n'<<res.m[1][0]<<' '<<res.m[1][1]<<'\n';
  // cout<<tr.m[0][0]<<' '<<tr.m[0][1]<<'\n'<<tr.m[1][0]<<' '<<tr.m[1][1]<<'\n';
  if(n==0LL) cout<<x<<'\n';
  else if(n==1LL) cout<<y<<'\n';
  else cout<<qpow(n-1)<<'\n';
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--) solve();
  return 0;
}