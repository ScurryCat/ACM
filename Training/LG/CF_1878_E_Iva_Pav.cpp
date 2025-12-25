#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m,ans;
int f[N][32];

bool check(int j,int k,int x){
  int y=f[j][0];
  for(int i=j;i<=x;i++){
    y&=f[i][0];
  }
  return y>=x;
}

void find(int j,int k){
  int l=0,r=n+1,mid;
  for(int i=1;i<31;i++){
    if(f[j][i]>=k&&f[j][i+1]<k){
      l=i;
      r=i+1;
      break;
    }
  }
  l=(1<<l)-1;
  r=(1<<r);
  while(l+1<r){
    mid=l+r>>1;
    if(check(j,k,mid)) l=mid;
    else r=mid;
  }
  if(check(j,k,l)) cout<<l<<' ';
  else cout<<-1<<' ';
}

void solve(){
	cin>>n;
  for(int i=1;i<=n;i++){
    cin>>f[i][0];
  }
  for(int i=1;i<30;i++){
    for(int j=1;j+(1<<i)-1<=n;j++){
      f[j][i]=f[j-1][i-1]&f[j][i-1];
    }
  }
  cin>>m;
  while(m--){
    int l,k;
    cin>>l>>k;
    find(l,k);
  }
  cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}
