#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 1e9+7;

int n,m;
int a[N],dp[N];

void qwq_(){
	cin>>n>>m;
  vector<int> a(n+1);
  vector<ll> f(m+1);  // f[i]表示支付i元时有多少种组合方案。  f[i] = f[i]+f[i-x]
  for(int i=1;i<=n;i++) cin>>a[i];
  f[0]=1;
  // for(int i=1;i<=n;i++){
  //   int x; cin>>x;
  //   for(int j=x;j<=m;j++){
  //     f[j] = (f[j]+f[j-x]) % mod;
  //   }
  // }
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if(i>=a[j]) f[i] = (f[i]+f[i-a[j]]) % mod;
    }
  }
  cout<<f[m];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}