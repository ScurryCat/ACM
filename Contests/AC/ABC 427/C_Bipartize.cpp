#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;
int ma[15][15];
int e[15];

void solve(){
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		ma[u][v]=1;
		ma[v][u]=1;
		e[u]++;
		e[v]++;
	}
	for(int i=1;i<=n;i++){
		if(e[i]%2){
			for(int j=1;j<=n;j++){
				if(ma[i][j]){
					if(e[j]%2){
						ans++;
						ma[i][j]=0;	
						ma[j][i]=0;	
						e[i]--;
						e[j]--;
					}
					if(j==n){
						ans++;
						ma[i][j]=0;
						ma[j][i]=0;
						e[i]--;
						e[j]--;
					}
				}
			}
		}
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}