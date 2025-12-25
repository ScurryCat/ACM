#include <bits/stdc++.h>
using namespace std;

#define lc u<<1
#define rc u<<1|1
#define endl '\n'
const int N = 2e5+9, mod = 998244353;
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

int n,m;
int fa[N],son[N],dep[N],top[N],sz[N];
struct edge{int v,w,ne;}e[N<<1];
struct {int u,v,w;}edges[N];
int h[N],tot;
int c[N],nc[N],id[N],idx;
struct node{
	int l,r;
	ll sum;
	int mx,mn,p;
}tr[N<<2];

inline void add(int u,int v,int w){
	e[++tot].v=v; e[tot].w=w; e[tot].ne=h[u]; h[u]=tot;
}

inline void dfs1(int u,int f){
	fa[u]=f; dep[u]=dep[f]+1; sz[u]=1;
	for(int i=h[u];~i;i=e[i].ne){
		int v=e[i].v;
		if(v==f) continue;
		c[v]=e[i].w;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v]) son[u]=v;
	}
}

inline void dfs2(int u,int t){
	top[u]=t; id[u]=++idx; nc[idx]=c[u];
	if(!son[u]) return;
	dfs2(son[u],t);
	for(int i=h[u];~i;i=e[i].ne){
		int v=e[i].v, w=e[i].w;
		if(v==fa[u] || v==son[u]) continue;
		dfs2(v,v);
	}
}

inline void pushup(int u){
	tr[u].sum=tr[lc].sum+tr[rc].sum;
	tr[u].mx=max(tr[lc].mx,tr[rc].mx);
	tr[u].mn=min(tr[lc].mn,tr[rc].mn);
}

inline void pushdown(int u){
	if(tr[u].p!=1){
		tr[lc].p*=tr[u].p;
		tr[rc].p*=tr[u].p;
		tr[lc].sum*=tr[u].p;
		tr[rc].sum*=tr[u].p;
		tr[lc].mx*=tr[u].p;
		tr[rc].mx*=tr[u].p;
		tr[lc].mn*=tr[u].p;
		tr[rc].mn*=tr[u].p;
		swap(tr[lc].mx,tr[lc].mn);
		swap(tr[rc].mx,tr[rc].mn);
		tr[u].p=1;
	}
}

inline void build(int u,int l,int r){
	tr[u]={l,r,nc[l],nc[l],nc[l],1};
	if(l==r) return;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(u);
}

inline ll querysum(int u,int x,int y){
	if(x<=tr[u].l && tr[u].r<=y) return tr[u].sum;
	pushdown(u);
	int m=tr[u].l+tr[u].r>>1;
	ll r=0;
	if(x<=m) r+=querysum(lc,x,y);
	if(y>m) r+=querysum(rc,x,y);
	return r;
}

inline int querymax(int u,int x,int y){
	if(x<=tr[u].l && tr[u].r<=y) return tr[u].mx;
	pushdown(u);
	int m=tr[u].l+tr[u].r>>1;
	int r=-1e9;
	if(x<=m) r=max(r,querymax(lc,x,y));
	if(y>m) r=max(r,querymax(rc,x,y));
	return r;
}

inline int querymin(int u,int x,int y){
	if(x<=tr[u].l && tr[u].r<=y) return tr[u].mn;
	pushdown(u);
	int m=tr[u].l+tr[u].r>>1;
	int r=1e9;
	if(x<=m) r=min(r,querymin(lc,x,y));
	if(y>m) r=min(r,querymin(rc,x,y));
	return r;
}

inline void update(int u,int x,int k){
	if(tr[u].l==tr[u].r){
		tr[u].sum=k;
		tr[u].mx=k;
		tr[u].mn=k;
		tr[u].p=1;
		return;
	}
	pushdown(u);
	int m=tr[u].l+tr[u].r>>1;
	if(x<=m) update(lc,x,k);
	if(x>m) update(rc,x,k);
	pushup(u);
}

inline void updatepath(int u,int x,int y,int k){
	if(x<=tr[u].l && tr[u].r<=y){
		tr[u].p*=k;
		tr[u].sum*=k;
		tr[u].mx*=k;
		tr[u].mn*=k;
		swap(tr[u].mx,tr[u].mn);
		return;
	}
	pushdown(u);
	int m=tr[u].l+tr[u].r>>1;
	if(x<=m) updatepath(lc,x,y,k);
	if(y>m) updatepath(rc,x,y,k);
	pushup(u);
}

inline ll querypathsum(int u,int v){
	ll r=0;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		r+=querysum(1,id[top[u]],id[u]);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v]) swap(u,v);
	r+=querysum(1,id[v]+1,id[u]);
	return r;
}

inline int querypathmax(int u,int v){
	int r=-1e9;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		r=max(r,querymax(1,id[top[u]],id[u]));
		u=fa[top[u]];
	}
	if(dep[u]<dep[v]) swap(u,v);
	r=max(r,querymax(1,id[v]+1,id[u]));
	return r;
}

inline int querypathmin(int u,int v){
	int r=1e9;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		r=min(r,querymin(1,id[top[u]],id[u]));
		u=fa[top[u]];
	}
	if(dep[u]<dep[v]) swap(u,v);
	r=min(r,querymin(1,id[v]+1,id[u]));
	return r;
}

inline void updatepoint(int u,int k){
	update(1,u,k);
}

inline void updatepm(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		updatepath(1,id[top[u]],id[u],-1);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v]) swap(u,v);
	updatepath(1,id[v]+1,id[u],-1);
}

inline void qwq_(){
	cin>>n;
	memset(h,-1,sizeof h);
	for(int i=1;i<n;i++){
		cin>>edges[i].u>>edges[i].v>>edges[i].w;
		edges[i].u++,edges[i].v++;
		add(edges[i].u,edges[i].v,edges[i].w);
		add(edges[i].v,edges[i].u,edges[i].w);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	cin>>m;
	while(m--){
		string s; 
		int u,v;
		cin>>s>>u>>v;
		u++,v++;
		if(s=="C"){
			u--,v--;
			updatepoint(dep[edges[u].u]>dep[edges[u].v]?id[edges[u].u]:id[edges[u].v],v);
		}
		else if(s=="N"){
			updatepm(u,v);
		}
		else if(s=="SUM"){
			cout<<querypathsum(u,v)<<'\n';
		}
		else if(s=="MAX"){
			cout<<querypathmax(u,v)<<'\n';
		}
		else if(s=="MIN"){
			cout<<querypathmin(u,v)<<'\n';
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