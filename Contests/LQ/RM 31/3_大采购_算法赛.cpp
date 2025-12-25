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

ll n,m,cnt,ans;

void solve(){
	cin>>n>>m;
	vector<long long> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	for(int i=1;i<=n;cnt++,i++){
		ans+=max(a[i]-cnt*m,0ll);
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