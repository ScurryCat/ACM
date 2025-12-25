#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 1e9+7;

ll n;
struct matrix{
  ll c[4][4];
  matrix(){memset(c,0,sizeof c);}
};

matrix operator*(matrix &a,matrix &b){
  matrix t;
  for(int i=1;i<=3;i++)
    for(int k=1;k<=3;k++)
      for(int j=1;j<=3;j++)
        t.c[i][j]=(t.c[i][j]+a.c[i][k]*b.c[k][j]) % mod;
  return t;
}

void quickpow(matrix & A,ll m){
  matrix B;
  B.c[1][1]=B.c[1][3]=B.c[2][1]=B.c[3][2]=1;
  while(m){
    if(m&1) A = A * B;
    B = B * B;
    m >>= 1;
  }
}

void solve(){
	matrix A;
  A.c[1][1]=A.c[1][2]=A.c[1][3]=1;
  cin>>n;
  if(n>3) quickpow(A,n-3);
  // cout<<A.c[1][1]<<' '<<A.c[1][2]<<' '<<A.c[1][3]<<'\n';
  cout<<A.c[1][1]<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}