#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e4+9, mod = 998244353;

int ww[N], vv[N];
int f[N]; // f[i]表示花费i体力时，能搬运的最大体积

void qwq_(){
	int v,n,c;
	cin>>v>>n>>c;
	for(int i=1;i<=n;i++) cin>>vv[i]>>ww[i];
	for(int i=1;i<=n;i++){
		for(int j=c;j>=ww[i];j--){
			f[j]=max(f[j],f[j-ww[i]]+vv[i]);
		}
	}
	for(int i=1;i<=c;i++){
		if(f[i]>=v){
			cout<<c-i;
			return ;
		}
	}
	cout<<"Impossible";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}