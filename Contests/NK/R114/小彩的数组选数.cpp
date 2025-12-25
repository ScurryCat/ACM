#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 2e5+9, mod = 998244353;

int n,ans=0;
int dp[N];

void solve(){
  cin>>n;
  VI a(n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  dp[1]=a[1];
  for(int i=2;i<=n;i++){
    dp[i]=max(dp[i-1],dp[i-2]+a[i]);
  }
  cout<<dp[n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}