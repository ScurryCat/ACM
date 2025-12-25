#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 3e2+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m;
int a[N][N];
int ma[N],mi[N];

void solve(){
	int x,cnt=0;
	memset(ma,0,sizeof ma);
	memset(mi,0x7f,sizeof mi);
	cin>>n>>m>>x;
	// for(int i=1;i<=m;i++) cout<<ma[i]<<' '<<mi[i]<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			ma[j]=max(a[i][j],ma[j]);
			mi[j]=min(a[i][j],mi[j]);
			if(a[i][j]!=ma[j]&&a[i][j]!=mi[j]){
				if(ma[j]-a[i][j]>=2||a[i][j]-mi[j]>=2){
					
				}
			}
		}
	}
	int c;	cin>>c;
	
	if(n<=2) cnt=c+1;
	for(int i=1;i<=m;i++){
		if(a[x][i]==ma[i]||a[x][i]==mi[i]){
			cnt++;
		}
		if(ma[i]-mi[i]<=1) cnt=c+1;
	}
	if(cnt<=c) cout<<"down\n";
	else cout<<"up\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}