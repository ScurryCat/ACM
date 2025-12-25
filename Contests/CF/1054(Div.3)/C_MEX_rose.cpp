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

int n,m;

void solve(){
	cin>>n>>m;
	VI a(n),vis(n+1);
	int ans=0,cnt=0,cnt2=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		vis[a[i]]++;
		if(a[i]==m) cnt++;
	}
	for(int i=0;i<m;i++){
		if(vis[i]==0) cnt2++;
	}
	cout<<max(cnt,cnt2)<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}