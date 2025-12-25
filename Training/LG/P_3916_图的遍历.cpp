#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m;
vector<vector<int>> e;
VI ans;

void dfs(int u){
	for(int v:e[u]){
		if(ans[v]) continue;
		ans[v]=ans[u];
		dfs(v);
	}
}

void solve(){
	cin>>n>>m;
	e.resize(n+1);
	ans.resize(n+1,0);
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		e[b].push_back(a);
	}
	for(int i=n;i>=1;i--){
		if(ans[i]) continue;
		ans[i]=i;
		dfs(i);
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}
