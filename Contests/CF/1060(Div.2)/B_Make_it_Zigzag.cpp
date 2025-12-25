#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void solve(){
	int n,mx=0;
	ll ans=0;
	cin>>n;
	VI a(n+1);
	a[0]=1e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i%2==0) a[i]=max(a[i],mx);
		mx=max(mx,a[i]);
		// cout<<a[i]<<' ';
	}
	// cout<<'\n';
	for(int i=1;i<=n;i++){
		if(i%2){
			if(a[i]>=a[i-1]){
				ans+=a[i]-a[i-1]+1;
				a[i]=a[i-1]-1;
			}
			if(i<n&&a[i]>=a[i+1]){
				ans+=a[i]-a[i+1]+1;
				a[i]=a[i+1]-1;
			}
		}
	}
	cout<<ans<<'\n';

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) solve();
	return 0;
}