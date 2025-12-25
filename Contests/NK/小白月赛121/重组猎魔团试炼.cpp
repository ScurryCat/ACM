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

ll n,d;
int cnt[11];

void solve(){
	cin>>n>>d;
  for(int i=1;i<=n;i++){
    char x;
    cin>>x;
    cnt[x-'0']++;
  }
  if(cnt[0]) cout<<0;
  else{
    ll m=pow(10,n);
    for(ll i=d;i<=m;i+=d){
      ll j=i;
      bool ok=true;
      int cp[11];
      for(int i=0;i<10;i++) cp[i]=cnt[i];
      while(j){
        if(cp[j%10]==0) ok=false;
        else cp[j%10]--;
        j/=10;
      }
      if(ok){
        cout<<i;
        return;
      }
    }
    cout<<-1;
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