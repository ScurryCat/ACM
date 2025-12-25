#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 1e3+9;
const int mod = 1e9+7;
struct matrix{
  ll c[N][N];
  matrix(){memset(c,0,sizeof c);}           // 矩阵的构造函数
}A,res;
ll n,k;

matrix operator*(matrix &x,matrix &y){      // 重载运算符 矩阵乘法
  matrix t;
  for(int i=1;i<=n;i++){                    // 三重循环，时间复杂度O(n3logk)
    for(int j=1;j<=n;j++){  
      for(int k=1;k<=n;k++){
        t.c[i][j]=(t.c[i][j]+x.c[i][j]*y.c[k][j]) % mod;
      }
    }
  }
  return t;
}

void quickpow(ll k){                        // 由于矩阵乘法满足结合律，因此可以使用快速幂加速计算 
  for(int i=1;i<=n;i++) res.c[i][i]=1;      // 单位矩阵
  while(k){
    if(k&1) res = res*A;
    A = A*A;
    k >>= 1;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      cin>>A.c[i][j];
  quickpow(k);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
      cout<<res.c[i][j]<<' ';
    cout<<'\n';
  }
  return 0;
}