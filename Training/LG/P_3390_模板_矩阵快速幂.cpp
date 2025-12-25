#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 1e2+9;
const int M = 2e5+9;
const int mod = 1e9+7;

ll n,k;
struct matrix{
  ll c[N][N];
  matrix(){memset(c,0,sizeof c);}
}A,res;

matrix operator*(matrix &x,matrix &y){
  matrix t;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      for(int k=1;k<=n;k++)
        t.c[i][j]=(t.c[i][j]+x.c[i][k]*y.c[k][j])%mod;
  return t;
}

void quickpow(ll k){
  for(int i=1;i<=n;i++) res.c[i][i]=1;
  while(k){
    if(k&1) res=res*A;
    A=A*A;
    k>>=1;
  }
}

void solve(){
	cin>>n>>k;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>A.c[i][j];
    }
  }
  quickpow(k);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cout<<res.c[i][j]<<' ';
    }
    cout<<'\n';
  }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}