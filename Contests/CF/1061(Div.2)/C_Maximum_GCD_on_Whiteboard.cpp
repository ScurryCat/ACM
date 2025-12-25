#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void solve(){
	int n,k,ans=1;
	cin>>n>>k;
	VI a(n+1,0);
	VI s(n+1);
	for(int i=1;i<=n;i++){
		int x; 
		cin>>x;
		a[x]++;
	}

	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];

	auto A=[&](int idx)->int{
		return (idx>=1&&idx<=n)?a[idx]:0;
	};

	for(int i=n;i>=1;i--){
		ll y=4*i-1;
		if(y>n) y=n;
		ll z=s[(int)y]-A(i)-A(i+i)-A(i+i+i);
		if(z<=k){
			ans=i;
			break;
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