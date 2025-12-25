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

int n;

int mp(int a,int b){
  int r=1;
  for(int i=1;i<=b;i++){
    r *= a;
  }
  return r;
}

void solve(){
	cin>>n;
  // VI a(n+10,0);
  // vector<ll> s(n+10,0);
  ll cur=0,ne=0,ans=0;
  for(int i=1;i<=n;i++){
    int j=1;
    while(i%mp(5,j)==0) j++;
    // a[i]=a[i-1]+j-1;
    // s[i]=s[i-1]+a[i];
    cur += j-1;
    ans += cur;
  }
  // for(int i=1;i<=n;i++) cout<<i<<' '<<a[i]<<' '<<s[i]<<'\n';
  // cout<<s[n];
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