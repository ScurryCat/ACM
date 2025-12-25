#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int f(int t){
  int r=0;
  while(t){
    r+=t%10;
    t/=10;
  }
  return r;
}

void solve(){
	int n,ans[109]={1};
  cin>>n;
  if(n==1) cout<<1;
  else{
    for(int i=1;i<=n;i++){
      ans[i]=ans[i-1]+f(ans[i-1]);
    }
    cout<<ans[n-1];
  }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}