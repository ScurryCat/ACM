#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n,m; cin>>n>>m;
	vector<int> f(n+1);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int w; cin>>w;
		for(int j=n;j>=w;j--){
			f[j]=min(f[j],f[j-w]);
		}
	}
	cout<<f[n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}