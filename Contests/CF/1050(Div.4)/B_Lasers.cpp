#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m,x,y,ans;
int a,b;

void solve(){
  ans=0;
	cin>>n>>m>>x>>y;
  for(int i=1;i<=n;i++){
    cin>>a;
    if(a<y) ans++;
  }
  for(int i=1;i<=m;i++){
    cin>>b;
    if(b<x) ans++;
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
