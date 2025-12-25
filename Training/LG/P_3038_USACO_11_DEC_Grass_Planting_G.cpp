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

int fa[N],son[N],dep[N],sz[N],top[N];
int id[N],idx;
vector<int> e[N];
struct node{
	int l,r;
	ll sum,add;
}tr[N<<2];

inline void dfs1(int u,int f){
	fa[u]=f; dep[u]=dep[f]+1; sz[u]=1;
	for(int v : e[u]){
		if(v==f) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v]) son[u]=v;
	}
}

inline void dfs2(int u,int t){
	top[u]=t; id[u]=++idx;
	if(!son[u]) return;
	dfs2(son[u],t);
	for(int v : e[u]){
		if(v==fa[u] || v==son[u]) continue;
		dfs2(v,v);
	}
}

inline void pushup(int u){
	tr[u].sum=tr[lc].sum+tr[rc].sum;
}

inline void pushdown(int u){
	if(tr[u].add){
		tr[lc].sum+=tr[u].add*(tr[lc].r-tr[lc].l+1);
		tr[rc].sum+=tr[u].add*(tr[rc].r-tr[rc].l+1);
		tr[lc].add+=tr[u].add;
		tr[rc].add+=tr[u].add;
		tr[u].add=0;
	}
}

inline void build(int u,int l,int r){
	tr[u]={l,r,0,0};
	if(l==r) return;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(u);
}

inline void update(int u,int x,int y,ll k){
	if(x<=tr[u].l && tr[u].r<=y){
		tr[u].add+=k;
		tr[u].sum+=k*(tr[u].r-tr[u].l+1);
		return;
	}
	pushdown(u);
	int m=tr[u].l+tr[u].r>>1;
	if(x<=m) update(lc,x,y,k);
	if(y>m) update(rc,x,y,k);
	pushup(u);
}

inline ll query(int u,int x,int y){
	if(x<=tr[u].l && tr[u].r<=y) return tr[u].sum;
	pushdown(u);
	int m=tr[u].l+tr[u].r>>1;
	ll r=0;
	if(x<=m) r+=query(lc,x,y);
	if(y>m) r+=query(rc,x,y);
	return r; 
}

inline void updatepath(int u,int v,ll k){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		update(1,id[top[u]],id[u],k);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v]) swap(u,v);
	update(1,id[v]+1,id[u],k);
}

inline ll querypath(int u,int v){
	ll r=0;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		r+=query(1,id[top[u]],id[u]);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v]) swap(u,v);
	r+=query(1,id[v]+1,id[u]);
	return r;
}

inline void qwq_(){
	int n,m; cin>>n>>m;
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	while(m--){
		char ch;
		int x,y;
		cin>>ch>>x>>y;
		if(ch=='P'){
			updatepath(x,y,1);
		}
		else{
			cout<<querypath(x,y)<<'\n';
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