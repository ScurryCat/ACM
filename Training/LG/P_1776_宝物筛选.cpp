#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

// int f[N], g[N];

// void qwq_(){
// 	int n,m;
// 	cin>>n>>m;
// 	// vector<int> f(m+1),g(m+1);
// 	vector<int> q(m+1);
// 	for(int i=1;i<=n;i++){
// 		// swap(f,g);
// 		memcpy(g,f,sizeof f);
// 		int v,w,s;
// 		cin>>w>>v>>s;
// 		for(int j=0;j<v;j++){
// 			int h=0,t=-1;
// 			for(int k=j;k<=m;k+=v){
// 				if(h<=t && q[h]<k-s*v) h++;
// 				if(h<=t) f[k]=max(g[k],g[q[h]]+(k-q[h])/v*w);
// 				while(h<=t && g[k]>=g[q[t]]+(k-q[t])/v*w) t--;
// 				q[++t]=k;
// 			}
// 		}
// 	}
// 	// for(int i=1;i<=m;i++) cout<<f[i]<<' ';cout<<'\n';
// 	cout<<f[m]<<'\n';
// }

void qwq_(){
	int n,m;
	cin>>n>>m;
	vector<int> f(m+1);
	int v[N],w[N],idx=0;
	for(int i=1;i<=n;i++){
		int vv,ww,s;
		cin>>vv>>ww>>s;
		int k=1;
		while(s>k){
			v[++idx]=k*vv;
			w[idx] = k*ww;
			s-=k;
			k<<=1;
		}
		if(s){
			v[++idx]=s*vv;
			w[idx] = s*ww;
		}
	}
	for(int i=1;i<=idx;i++){
		for(int j=m;j>=w[i];j--){
			f[j]=max(f[j],f[j-w[i]]+v[i]);
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