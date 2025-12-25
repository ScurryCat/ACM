#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 800+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m;
int g[N][N];
int ans[N+N];
bool vis[N+N];

void solve(){
	memset(vis,false,sizeof vis);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
			ans[i+j]=g[i][j];
			vis[g[i][j]]=true;
		}
	}
	for(int i=1;i<=n+n;i++){
		if(!vis[i]){
			ans[1]=i;
			break;
		}
	}
	for(int i=1;i<=n+n;i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}
