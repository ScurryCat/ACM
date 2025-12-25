#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void solve(){
	int n; cin >> n;
	vector<ll> b(n+1,0);
	vector<ll> a(n+1,0);
	for(int i=1;i<=n;i++) cin>>b[i];
	int cur=0;

	for(int i=1;i<=n;i++){
		int p=i-((int)b[i]-b[i-1]);
		if(p==0) a[i]=++cur;
		else a[i]=a[p];
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
	cout<<'\n';
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) solve();
	return 0;
}