#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;  

const int N = 1e5+9, mod = 998244353;

int n,m;
int v[N],dp[N];

inline void qwq_(){
  cin>>m>>n;
  for(int i=1;i<=n;i++) cin>>v[i];
  
  for(int i=1;i<=n;i++){
    for(int j=m;j>=v[i];j--){
      dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
      // cout<<dp[j]<<' ';
    }
    // cout<<'\n';
  }
  cout<<m-dp[m]<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	while(yyy--) qwq_();
	return 0;
}