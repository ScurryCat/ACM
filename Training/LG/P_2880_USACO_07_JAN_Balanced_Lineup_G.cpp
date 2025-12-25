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
int ma[N][30],mi[N][30];
int LOG[N];

void solve(){
	cin>>n>>m;
  for(int i=1;i<=n;i++){
    cin>>ma[i][0];
    mi[i][0]=ma[i][0];
  }
  for(int i=2;i<=n;i++){
    LOG[i]=LOG[i/2]+1;
  }
  for(int j=1;j<=30;j++){
    for(int i=1;i+(1<<j)-1<=n;i++){
      ma[i][j]=max(ma[i][j-1],ma[i+(1<<(j-1))][j-1]);
      mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
    }
  }
  while(m--){
    int a,b,k;
    cin>>a>>b;
    k=LOG[b-a+1];
    cout<<max(ma[a][k],ma[b-(1<<k)+1][k])-min(mi[a][k],mi[b-(1<<k)+1][k])<<'\n';
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
