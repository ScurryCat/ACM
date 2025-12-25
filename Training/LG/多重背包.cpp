#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int w[N],v[N],f[N],cnt;

void qwq_(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x,ww,vv;
		cin>>x>>ww>>vv;
		int y=1;
		while(y<x){
			w[++cnt] = ww*y;
			v[cnt] = vv*y;
			x-=y;
		}
		if(x){
			w[++cnt] = ww*x;
			v[cnt] = vv*x;
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int j=m;j>=w[i];j--){
			f[j] = max(f[j],f[j-w[i]]+v[i]);
		}
	}
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