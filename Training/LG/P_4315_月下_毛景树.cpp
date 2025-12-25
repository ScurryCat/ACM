#include <bits/stdc++.h>
using namespace std;

#define lc u<<1
#define rc u<<1|1
#define endl '\n'
const int N = 1e5+9, mod = 998244353;
using ll = long long; using ld = long double; using i128 = __int128; int t_ = 1;

#ifndef ONLINE_JUDGE
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {os << "["; for(int i=0; i<v.size(); i++) os << (i?", ":"") << v[i]; return os << "]";}
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {return os << "(" << p.first << ", " << p.second << ")";}
void debug_out(vector<string> names, int idx) { cerr << endl;} template <typename Head, typename... Tail>
void debug_out(vector<string> names, int idx, Head H, Tail... T) {if (idx > 0) cerr << ", ";string name = names[idx]; name.erase(0, name.find_first_not_of(' ')); name.erase(name.find_last_not_of(' ') + 1);cerr << name << "=" << H;debug_out(names, idx + 1, T...);}
#define debug(...) {string _s = #__VA_ARGS__, _tmp; vector<string> _names; int _p = 0;for (char c : _s) {if (c == '(' || c == '{') _p++;else if (c == ')' || c == '}') _p--;else if (c == ',' && _p == 0) { _names.push_back(_tmp); _tmp = "";continue;}_tmp += c;} _names.push_back(_tmp);cerr << "T" << t_<< " Line " << __LINE__ << ": "; debug_out(_names, 0, __VA_ARGS__);}
#else
#define debug(...)
#endif

int n;
int h[N],tot,w[N],nw[N],id[N],idx;
int fa[N],son[N],top[N],dep[N],sz[N];
struct {int v,w,ne;}e[N<<1];
struct {int u,v,w;}es[N];
struct {int l,r,max,cover,add;}tr[N<<2];

inline void add(int u,int v,int w){
	e[++tot].v=v; e[tot].w=w; e[tot].ne=h[u]; h[u]=tot;
}

inline void dfs1(int u,int f){
	fa[u]=f; dep[u]=dep[f]+1; sz[u]=1;
	for(int i=h[u];~i;i=e[i].ne){
		int v=e[i].v;
		if(v==f) continue;
		w[v]=e[i].w;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v]) son[u]=v;
	}
}

inline void dfs2(int u,int t){
	top[u]=t; id[u]=++idx; nw[idx]=w[u];
	if(!son[u]) return;
	dfs2(son[u],t);
	for(int i=h[u];~i;i=e[i].ne){
		int v=e[i].v;
		if(v==fa[u] || v==son[u]) continue;
		dfs2(v,v);
	}
}

inline void pushup(int u){
	tr[u].max=max(tr[lc].max,tr[rc].max);
}

inline void pushdown(int u){
	if(tr[u].cover!=-1){
		tr[lc].cover=tr[u].cover;
		tr[rc].cover=tr[u].cover;
		tr[lc].max=tr[u].cover;
		tr[rc].max=tr[u].cover;
		tr[lc].add=0;
		tr[rc].add=0;
		tr[u].cover=-1;
	}
	if(tr[u].add){
		tr[lc].add+=tr[u].add;
		tr[rc].add+=tr[u].add;
		tr[lc].max+=tr[u].add;
		tr[rc].max+=tr[u].add;
		tr[u].add=0;
	}
}

inline void build(int u,int l,int r){
	tr[u]={l,r,nw[l],-1,0};
	if(l==r) return;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(u);
}

inline void updateadd(int u,int x,int y,int k){
	if(x<=tr[u].l && tr[u].r<=y){
		tr[u].add+=k;
		tr[u].max+=k;
		return;
	}
	pushdown(u);
	int m=tr[u].l+tr[u].r>>1;
	if(x<=m) updateadd(lc,x,y,k);
	if(y>m) updateadd(rc,x,y,k);
	pushup(u);
}

inline void updatecover(int u,int x,int y,int k){
	if(x<=tr[u].l && tr[u].r<=y){
		tr[u].add=0;
		tr[u].cover=k;
		tr[u].max=k;
		return; 
	}
	pushdown(u);
	int m=tr[u].l+tr[u].r>>1;
	if(x<=m) updatecover(lc,x,y,k);
	if(y>m) updatecover(rc,x,y,k);
	pushup(u);
}

inline int query(int u,int x,int y){
	if(x<=tr[u].l && tr[u].r<=y) return tr[u].max;
	pushdown(u);
	int m=tr[u].l+tr[u].r>>1;
	int r=-1e9;
	if(x<=m) r=max(r,query(lc,x,y));
	if(y>m) r=max(r,query(rc,x,y));
	return r;
}

inline void updatepointcover(int t,int k){
	int u=es[t].u, v=es[t].v;
	if(dep[u]<dep[v]) swap(u,v);
	updatecover(1,id[u],id[u],k);
}

inline void updatepathcover(int u,int v,int k){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		updatecover(1,id[top[u]],id[u],k);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v]) swap(u,v);
	if(id[v]+1<=id[u]) updatecover(1,id[v]+1,id[u],k);
}

inline void updatepathadd(int u,int v,int k){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		updateadd(1,id[top[u]],id[u],k);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v]) swap(u,v);
	if(id[v]+1<=id[u]) updateadd(1,id[v]+1,id[u],k);
}

inline int querypath(int u,int v){
	int r=-1e9;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		r=max(r,query(1,id[top[u]],id[u]));
		u=fa[top[u]];
	}
	if(dep[u]<dep[v]) swap(u,v);
	r=max(r,query(1,id[v]+1,id[u]));
	return r;
}

inline void qwq_(){
	cin>>n;
	memset(h,-1,sizeof h);
	for(int i=1;i<n;i++){
		cin>>es[i].u>>es[i].v>>es[i].w;
		add(es[i].u,es[i].v,es[i].w);
		add(es[i].v,es[i].u,es[i].w);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	string s;
	while(cin>>s){
		if(s=="Stop") break;
		if(s=="Change"){
			int q,k; cin>>q>>k;
			updatepointcover(q,k);
		}
		if(s=="Cover"){
			int u,v,k; cin>>u>>v>>k;
			updatepathcover(u,v,k);
		}
		if(s=="Add"){
			int u,v,k; cin>>u>>v>>k;
			updatepathadd(u,v,k);
		}
		if(s=="Max"){
			int u,v; cin>>u>>v;
			cout<<querypath(u,v)<<'\n';
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--){
		qwq_();
		t_+=1;
	}
	return 0;
}