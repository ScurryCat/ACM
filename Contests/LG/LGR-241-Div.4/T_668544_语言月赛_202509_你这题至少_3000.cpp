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

int n,m,cnt;
bool a[N];

void solve(){
	cin>>n>>m;
	memset(a,true,sizeof a);
	for(int i=1;i<=n;i++){
		int x;	cin>>x;
		if(x==m){
			if(a[x+1]){
				a[x+1]=false;
				cnt++;
			}
		}
		else{
			if(a[x+1]){
				a[x+1]=false;
				cnt++;
			}
			if(a[x+2]){
				a[x+2]=false;
				cnt++;
			}
		}
	}
	if(cnt==m) cout<<"Accepted";
	else{
		cout<<m-cnt<<'\n';
		for(int i=1;i<=m;i++){
			if(a[i+1]) cout<<i<<' ';
		}
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