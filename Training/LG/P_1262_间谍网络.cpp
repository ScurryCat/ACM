#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e4+9, mod = 998244353;
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

int n,m,p;
int tra[N],sm[N];
int h[N],to[N],ne[N],tot=1;
vector<pair<int,int>> e[N];
int stk[N],instk[N],top;
int dfn[N],low[N],idx;
int scc[N],cnt;
int din[N],vis[N];

inline void add(int u,int v){
	to[++tot]=v; ne[tot]=h[u]; h[u]=tot;
}

inline void tarjan(int u){
	dfn[u]=low[u]=++idx;
	stk[++top]=u; instk[u]=1;
	for(int i=h[u];i;i=ne[i]){
		int v=to[i];
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(instk[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		int v=0; cnt++;
		while(u!=v){
			v=stk[top--]; instk[v]=0;
			scc[v]=cnt;
			if(tra[v]!=0x3f3f3f3f) sm[cnt]=min(sm[cnt],tra[v]);
		}
	}
}

inline void mark(int u){
	if(vis[u]) return;
	vis[u]=1;
	for(auto ed : e[u]){
		int v=ed.first;
		mark(v);
	}
}

inline void qwq_(){
	cin>>n>>p;
	memset(sm,0x3f,sizeof sm);
	memset(tra,0x3f,sizeof tra);
	for(int i=1;i<=p;i++){
		int u,x; cin>>u>>x;
		tra[u]=x;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		int u,v; cin>>u>>v;
		add(u,v);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int u=1;u<=n;u++){
		for(int i=h[u];i;i=ne[i]){
			int v=to[i];
			if(scc[u]!=scc[v]){
				din[scc[v]]++;
				e[scc[u]].push_back({scc[v],sm[scc[v]]});
			}
		}
	}
	int total=0;
	for(int i=1;i<=cnt;i++){
		if(din[i]==0 && sm[i]!=0x3f3f3f3f){
			total+=sm[i];
			mark(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[scc[i]]){
			if(tra[i]!=0x3f3f3f3f) continue;
			cout<<"NO\n";
			cout<<i;
			return;
		}
	}
	cout<<"YES\n"<<total;
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