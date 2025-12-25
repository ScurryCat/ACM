#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 6e3+9, mod = 998244353;

int r[N],fa[N];
int f[N][2];
vector<int> t[N];

int dfs(int u,int k){
	if(f[u][k]) return f[u][k];
	if(k){
		f[u][k]=r[u];
		for(auto v : t[u]){
			f[u][k]+=dfs(v,0);
		}
	}
	else{
		for(auto v : t[u]){
			f[u][k]+=max(dfs(v,0),dfs(v,1));
		}
	}
	return f[u][k];
}

int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

void qwq_(){
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i],fa[i]=i;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		t[v].push_back(u);
		fa[u]=v;
	}
	cout<<max(dfs(find(1),0),dfs(find(1),1));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}