#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 5e4+9, mod = 998244353;

int n,m;
int h[N],to[N<<1],ne[N<<1],tot;
int fa[N],son[N],dep[N],top[N],sz[N];
int d[N];

inline void add(int u,int v){
	to[++tot]=v; ne[tot]=h[u]; h[u]=tot;
}

inline void dfs1(int u,int f){
	fa[u]=f; dep[u]=dep[f]+1; sz[u]=1;
	for(int i=h[u];~i;i=ne[i]){
		int v=to[i];
		if(v==f) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v]) son[u]=v;
	}
}

inline void dfs2(int u,int t){
	top[u]=t;
	if(!son[u]) return;
	dfs2(son[u],t);
	for(int i=h[u];~i;i=ne[i]){
		int v=to[i];
		if(v==fa[u] || v==son[u]) continue;
		dfs2(v,v);
	}
}

inline void dfs3(int u,int f){
	for(int i=h[u];~i;i=ne[i]){
		int v=to[i];
		if(v==f) continue;
		dfs3(v,u);
		d[u]+=d[v];
	}
}

inline int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}

void qwq_(){
	cin>>n>>m;
	memset(h,-1,sizeof h);
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	dfs1(1,0);
	dfs2(1,1);
	while(m--){
		int u,v; cin>>u>>v;
		d[u]++; d[v]++; d[lca(u,v)]--; d[fa[lca(u,v)]]--;
	}
	dfs3(1,0);
	sort(d+1,d+n+1,greater<int>());
	cout<<d[1];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}