#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int f[220][220];

void qwq_(){
	int n,m; cin>>n>>m;
	vector<int> v(n+1),w(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i]>>w[i];
	}
	for(int i=1;i<=n;i++){
		// for(int j=m;j>=v[i];j--){
		// 	f[j]=max(f[j],f[j-v[i]]^w[i]);
		// }
		for(int j=1;j<=m;j++){
			f[i][j] = max(f[i-1][j],f[i-1][j-v[i]]^w[i]);
		}
	}
	if(f[n][m]) cout<<f[n][m]<<'\n';
	else cout<<"1\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}