#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n,m; cin>>n>>m;
	vector<ll> f(m+1,0ll);
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		for(int j=m;j>=0;j--){
			if(j<c) f[j]=f[j]+a;
			else f[j]=max(f[j]+a,f[j-c]+b);
		}
	}
	cout<<5*f[m];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}