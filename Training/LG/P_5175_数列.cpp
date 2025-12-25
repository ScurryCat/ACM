#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 1000000007;

ll n,a1,a2,x,y;

struct matrix{
  ll m[5][5];
  matrix(){memset(m,0,sizeof m);};
};

matrix operator*(matrix &a,matrix &b){
  matrix r;
  for(int k=1;k<=4;k++)
    for(int i=1;i<=4;i++)
      for(int j=1;j<=4;j++)
        r.m[i][j] = (r.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
  return r;
}

ll quickpow(ll n){
  matrix A,T;
  A.m[1][1]=a1*a1%mod;
  A.m[1][2]=a2*a2%mod;
  A.m[1][3]=a1*a1%mod;
  A.m[1][4]=a1*a2%mod;
  T.m[1][1]=1;
  T.m[2][1]=1;
  T.m[2][2]=x*x%mod;
  T.m[3][2]=y*y%mod;
  T.m[4][2]=2*x*y%mod;
  T.m[2][3]=1;
  T.m[2][4]=x;
  T.m[4][4]=y;

  while(n){
    if(n&1) A = A * T;
    T = T * T;
    n>>=1;
  }
  return A.m[1][1];
}

void quickpow2(matrix &A,matrix &T,ull n){
  A.m[1][1]=a1*a1%mod;
  A.m[2][1]=a2*a2%mod;
  A.m[3][1]=a1*a1%mod;
  A.m[4][1]=a1*a2%mod;
  T.m[1][1]=1;
  T.m[1][2]=1;
  T.m[2][2]=x*x%mod;
  T.m[2][3]=y*y%mod;
  T.m[2][4]=2*x*y%mod;
  T.m[3][2]=1;
  T.m[4][2]=x;
  T.m[4][4]=y;

  while(n){
    if(n&1) A = T * A;
    T = T * T;
    n >>= 1;
  }
}

void qaq_(){
	cin>>n>>a1>>a2>>x>>y;
  cout<<quickpow(n-1)<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qaq_();
	return 0;
}