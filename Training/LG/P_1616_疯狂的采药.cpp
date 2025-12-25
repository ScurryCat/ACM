#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;



void qaq_(){
	int n,m; cin>>n>>m;
	vector<ll> f(n+1);
	for(int i=1;i<=m;i++){
		int w,v; cin>>w>>v;
		for(int i=w;i<=n;i++){
			f[i]=max(f[i],f[i-w]+v);
		}
	}
	cout<<f[n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qaq_();
	return 0;
}