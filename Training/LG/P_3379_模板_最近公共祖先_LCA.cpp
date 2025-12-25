#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 5e5+9, mod = 998244353;

int n,m,s;
vector<int> e[N];
int dep[N], fa[N][20];

void dfs(int u, int father){
	dep[u]=dep[father]+1;
	fa[u][0]=father;
	for(int i=1;i<20;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(int v : e[u]){
		if(v!=father) dfs(v,u);
	}
}

int lca(int u, int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=19;i>=0;i--){
		if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	}
	if(u==v) return v;
	for(int i=19;i>=0;i--){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return fa[u][0];
}

void qwq_(){
	cin>>n>>m>>s;
	for(int i=1;i<n;i++){
		int u, v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(s,0);
	while(m--){
		int u, v;
		cin>>u>>v;
		cout<<lca(u,v)<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}