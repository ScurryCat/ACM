#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 3e5+9, mod = 998244353;
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
int d[N];
int cnt[N]; ll mx;
struct edge{int v,w;};
vector<edge> e[N];

inline void dfs1(int u,int f){
	fa[u]=f; dep[u]=dep[f]+1; sz[u]=1;
	for(auto ed : e[u]){
		int v=ed.v,c=ed.w;
		if(v==f) continue;
		d[v]=d[u]+c;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v]) son[u]=v;
	}
}

inline void dfs2(int u,int t){
	top[u]=t;
	if(!son[u]) return;
	dfs2(son[u],t);
	for(auto ed : e[u]){
		int v=ed.v;
		if(v==fa[u] || v==son[u]) continue;
		dfs2(v,v);
	}
}

inline void dfs3(int u, int f){
  for(auto ed : e[u]){
    int v=ed.v;
    if(v==f) continue;
    dfs3(v,u);
    cnt[u]+=cnt[v];
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

inline void qwq_(){
	int n,m; cin>>n>>m;
	for(int i=1;i<n;i++){
		int u,v,c; cin>>u>>v>>c;
		e[u].push_back({v,c});
		e[v].push_back({u,c});
	}
	dfs1(1,0);
	dfs2(1,1);
	ll ans=0;
	while(m--){
		int u,v; cin>>u>>v;
		cnt[u]++; cnt[v]++; cnt[lca(u,v)]-=2;
		ans+=d[u]+d[v]-2*d[lca(u,v)];
	}
	dfs3(1,0);
	for(int i=1;i<=n;i++){
		mx=max(mx,(ll)cnt[i]*(d[i]-d[fa[i]]));
	}
	debug(ans,mx);
	cout<<ans-mx;
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