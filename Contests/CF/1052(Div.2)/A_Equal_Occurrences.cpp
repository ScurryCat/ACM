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

int n,m;

void solve(){
	cin>>n;
  m=0;
  int ma=0;
  VI a;
  VI cnt(n+1,0);
  for(int i=1;i<=n;i++){
    int x;  cin>>x;
    ma=max(ma,x);
    if(!cnt[x]) m++;
    cnt[x]++;
  }
  for(int i=1;i<=n;i++){
    if(cnt[i]) a.push_back(cnt[i]);
  }
  int ans=0;
  sort(a.begin(),a.end());
  for(int i=0;i<m;i++){
    for(int j=1;j<=ma;j++){
      if(cnt[j]==a[i]){
        ans=max(ans,(m-i)*cnt[j]);
        // cout<<ans<<'\n';
        break;
      }
    }
  }
  cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}