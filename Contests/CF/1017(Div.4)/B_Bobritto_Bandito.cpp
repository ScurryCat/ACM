#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m,l,r,ans;

void solve(){
	cin>>n>>m>>l>>r;
	// cout<<max(-m,l+n-m)<<' '<<min(m,r-n+m)<<'\n';
	// if(r==n) cout<<l+(n-m)+1<<' '<<r-(n-m)<<'\n';
	// else if(l==-n) cout<<l+(n-m)<<' '<<r-(n-m)-1<<'\n';
	// else cout<<l+(n-m)+1<<' '<<r-(n-m)-1<<'\n';
	int ll,rr;
	// if(l==-n){
	// 	ll=l+(n-m);
	// 	rr=max(ll+1,r-(n-m));
	// }
	// else{
	// 	rr=(r-(n-m));
	// 	ll=min(l+(n-m),rr-1);
	// }
	ll=max(-m,l);
	rr=ll+m;
	cout<<ll<<' '<<rr<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}
