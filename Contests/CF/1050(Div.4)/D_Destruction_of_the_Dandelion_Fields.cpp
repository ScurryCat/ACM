#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

ll n,m;

void solve(){
	vector<ll> a;
	ll ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		if(m&1) a.push_back(m);
		else ans+=m;
	}
	sort(a.begin(),a.end(),greater<ll>());
	// for(int i=0;i<a.size();i++) cout<<a[i]<<' ';
	if(a.size()&1) for(int i=0;i<(a.size())/2+1;i++) ans+=a[i];
	else for(int i=0;i<(a.size())/2;i++) ans+=a[i];
	if(a.size()) cout<<ans<<'\n';
	else cout<<0<<'\n';
	a.clear();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}
