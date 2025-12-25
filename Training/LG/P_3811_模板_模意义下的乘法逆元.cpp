#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,p;

int qpow(ll a,int b,int p){
  int r=1;
  while(b){
    if(b&1) r=(r*a)%p;
    a=(a*a)%p;
    b>>=1;
  }
  return r;
}

void solve(){
	cin>>n>>p;
  // for(int i=1;i<=n;i++){  // 由于n最大可到3e6，p最大可到2e7，此解法时间复杂度为O(nlogp)，会TLE。
  //   cout<<qpow(i,p-2,p)<<'\n';
  // }

  // 由于是对1-n区间内连续的数求其逆元，可以考虑线性递推的做法
  vector<int> inv(n+1);
  inv[1]=1;
  cout<<inv[1]<<'\n';
  for(int i=2;i<=n;i++){
    inv[i] = inv[p%i] * (p - p/i) % p;
    cout<<inv[i]<<'\n';
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