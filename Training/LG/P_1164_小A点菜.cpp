#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n,m; cin>>n>>m;
	vector<int> f(n+1); // f[i]表示刚好花完i元的方案数。  f[i]=f[i]+f[i-x]
	f[0]=1;
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		for(int j=m;j>=x;j--){
			f[j]+=f[j-x];
		}
	}
	// for(int i=1;i<=m;i++) cout<<f[i]<<' ';cout<<'\n';
	cout<<f[m];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}