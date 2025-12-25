#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;

const int N = 2e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m;
int a[N],b[N];
ll cost;

void solve(){
  cost=0;
  cin>>n>>m;
  for(int i=1;i<=n;i++) cin>>a[i];
  for(int i=1;i<=m;i++) cin>>b[i];
  sort(a+1,a+n+1);
  sort(b+1,b+m+1);
  int i,j;
  for(i=1,j=n;i<=m&&j>=1;i++){
    // for(int k=j;k>j-(b[i]-1)&&k>=1;k--){   // 这种做法为什么会WA？ 是k小于1了吗？  哦还真是
    //   // cout<<a[k]<<" ";
    //   cost+=a[k];
    // }
    a[j-b[i]+1]=0;
    j-=b[i];
  }
  // for(;j>=1;j--){
  //   cost+=a[j];
  // }
  for(int i=1;i<=n;i++) cost+=a[i];
  cout<<cost<<'\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  
  int T = 1;
  cin>>T;
  while(T--) solve();
  return 0;
}