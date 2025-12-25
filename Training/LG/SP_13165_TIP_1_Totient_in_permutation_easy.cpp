#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 1e7+9;
const int M = 2e5+9;
const int mod = 998244353;

int n;
int p[N],cnt,phi[N];
bool vis[N];

void getphi(int n){
  for(int i=2;i<=n;i++){
    if(!vis[i]){
      p[++cnt]=i;
      phi[i]=i-1;
    }
    for(int j=1;i*p[j]<=n;j++){
      int m=i*p[j];
      vis[m]=true;
      if(i%p[j]==0){
        phi[m]=phi[i]*(p[j]-1);
        break;
      }
      else phi[m]=phi[i]*phi[p[j]];
    }
  }
}

void solve(){
	cin>>n;
  int ans=2;
  double cur=2;
  for(int i=2;i<n;i++){
    if(i<phi[i]*cur){
      ans=i;
      cur=i*1.0/phi[i];
    }
  }
  cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
  getphi(1e7);
	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}