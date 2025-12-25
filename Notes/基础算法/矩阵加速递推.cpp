#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 1e3+9;
const int mod = 1e9+7;
struct matrix{
  ll c[3][3];
  matrix(){memset(c,0,sizeof c);}           // 矩阵的构造函数
}A,F;
ll n;

matrix operator*(matrix &x,matrix &y){
  matrix t;
  for(int i=1;i<=2;i++)
    for(int k=1;k<=2;k++)
      for(int j=1;j<=2;j++)
        t.c[i][j]=(t.c[i][j]+x.c[i][k]*y.c[k][j]) % mod;
  return t;
}

void quickpow(ll n){                       // 时间复杂度O(2^3logn)
  A.c[1][1]=A.c[1][2]=A.c[2][1]=1;
  A.c[2][2]=0;
  while(n){
    if(n&1) F = F * A;                     // 注意矩阵乘法不满足交换律，此处必须是F*A
    A = A * A;
    n >>= 1;
  }
}

void solve(){
  F.c[1][1]=F.c[1][2]=1;
  cin>>n;
  if(n>2) quickpow(n-2);
  cout<<F.c[1][1]<<' ';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int T=1;  cin>>T;
  while(T--) solve();
  return 0;
}