#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5+9;
const int M = 2e5+9;
const int mod = 998244353;

int n,m,ans;
int a[N],b[N];

void solve(){
	ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		if(b[i]==b[i-1]){
			if(a[i]-a[i-1]>1)
				ans+=(a[i]-a[i-1])/2*2;
		}
		else{
			ans++;
			if(a[i]-a[i-1]>2)
				ans+=(a[i]-a[i-1]-1)/2*2;
		}
		//cout<<ans<<'\n';
	}
	ans+=m-a[n];
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}
