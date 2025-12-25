#include <bits/stdc++.h>
using namespace std;

#define rll register long long

typedef vector<int> VI;
typedef vector<double> VD;
typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;

const int N=3e2+9;
const int M=1e3+9;
const int mod=1e9+7;

int n,W,w[N],t[N];
double c[M];
ll ans;

// 考虑使用01背包
bool check(double x){
  for(int i=1;i<=W;i++) c[i]=-1e9;
  for(int i=1;i<=n;i++){
    for(int j=W;j>=0;j--){
      int k=min(W,j+w[i]);
      c[k]=max(c[k],c[j]+t[i]-x*w[i]);
    }
  }
  return c[W]>=0;
}
 
void solve(){
	cin>>n>>W;
  for(int i=1;i<=n;i++){
    cin>>w[i]>>t[i];
  }
  double l=0,r=1e3,mid;
  while(r-l>1e-6){
    mid=(l+r)/2;
    if(check(mid)) l=mid;
    else r=mid;
  }
  printf("%d",(int)(r*1000));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	int T=1;
	//cin>>T;
	while(T--) solve();

	return 0;
}