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
int cnt[N];

void solve(){
	cin>>n>>m;
  ll ans=0;
  VI a(n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
    cnt[a[i]]++;
  }
  sort(a.begin(),a.end());
  for(int i=n;i>=1;i--){
    ans=max(ans,(ll)a[i]*min(cnt[a[i]],m));
  }
  cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}