#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m,ans;
int f[N][31];
int logN[N];

void solve(){
	cin>>n>>m;
  for(int i=1;i<=n;i++){
    cin>>f[i][0];
  }
  for(int i=2;i<=n;i++){
    logN[i]=logN[i/2]+1;
  }
  for(int j=1;j<=30;j++){
    for(int i=1;i+(1<<j)-1<=n;i++){
      f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    }
  }
  while(m--){
    int l,r;
    cin>>l>>r;
    int k=logN[r-l+1];
    cout<<max(f[l][k],f[r-(1<<k)+1][k])<<'\n';
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
