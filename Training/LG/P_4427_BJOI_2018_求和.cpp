#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef unsigned long long ull;

const int N = 3e5+9;
const int mod = 998244353;

int n,m;
int h[N],to[N<<1],ne[N<<1],tot;
int fa[N],son[N],dep[N],sz[N],top[N];
ll s[N][51],mi[51];

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
	for(int i=1;i<=50;i++) mi[i]=(mi[i-1]*dep[u])%mod;
	for(int i=1;i<=50;i++) s[u][i]=(s[fa[u]][i]+mi[i])%mod;
	if(!son[u]) return;
	dfs2(son[u],t);
	for(int i=h[u];~i;i=ne[i]){
		int v=to[i];
		if(v==fa[u] || v==son[u]) continue;
		dfs2(v,v);
	}
}

inline int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v]) swap(u,v);
	return v;
}

void solve(){
  cin>>n;
	memset(h,-1,sizeof h);
  for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		add(u,v);
		add(v,u);
  }
	mi[0]=1;
	dep[0]=-1;
	dfs1(1,0);
	dfs2(1,1);
	cin>>m;
	while(m--){
		int u,v,k; cin>>u>>v>>k;
		cout<<(s[u][k]+s[v][k]-s[lca(u,v)][k]-s[fa[lca(u,v)]][k]+mod+mod)%mod<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}
