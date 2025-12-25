#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 1e9+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m;
// bool vis[N];

void solve(){
	cin>>n;
	// memset(vis,0,sizeof vis);
	// bool ok=true;
	// for(int i=0;i<n;i++){
	// 	int x; cin>>x;
	// 	if(vis[x]) ok=false;
	// 	vis[x]++;
	// }
	vector<int> a(n);
	bool ok=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	for(int i=0;i+1<n;i++) if(a[i]==a[i+1]) ok=false;
	if(ok) cout<<"YES\n";
	else cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}