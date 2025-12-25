#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int r = 0, w = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w *= -1; ch = getchar();}
	while('0' <= ch && ch <= '9') {r = (r << 1) + (r << 3) + ch - 48; ch = getchar();}
	return r * w;
}

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e6+9;
const int mod = 998244353;

int p[50000],idx;
bool vis[N];

void ora(){
	for(int i=2;i<=50000;i++){
		if(!vis[i]) p[++idx]=i;
		for(int j=1;i*p[j]<=50000;j++){
			vis[i*p[j]]=true;
			if(i%p[j]==0) break;
		}
	}
}

void solve(){
	ora();
	int l,r,ans=0,s=2;
	cin>>l>>r;
	if(l==1) l=2;
	memset(vis,0,sizeof vis);
	ans=r-l+1;
	for(int i=1;i<=idx;i++){
		for(ll j=max(2,(l-1)/p[i]+1)*p[i];j<=r;j+=p[i]){
			if(j>=l && !vis[j-l+1]){
				// cout<<j<<' ';
				ans--;
				vis[j-l+1]=1;
			}
		}
	}
	cout<<ans;
	// for(int i=1;i<=r-l+1;i++) 
	// 	if(!vis[i]) cout<<i+l-1<<' ';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// yyy = read();
	while(yyy--) solve();
	return 0;
}