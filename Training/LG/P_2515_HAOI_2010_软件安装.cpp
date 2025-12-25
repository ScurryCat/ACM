#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e2+9, M = 5e2+9, mod = 998244353; int t_ = 1;
using ll = long long; using ld = long double; using i128 = __int128;

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
int w[N],v[N],d[N];
vector<int> e[N],ne[N];
int f[N][M]; // f[i][j]表示以i为根的，大小不超过j的子树所能安装的最大价值
int dfn[N],low[N],idx;
int stk[N],instk[N],top;
int scc[N],din[N],nw[N],nv[N],cnt;

inline int install(int u){
	if(e[u].size()) return w[u]+install(e[u][0]);
	return w[u];
}

inline void tarjan(int u){
	dfn[u]=low[u]=++idx;
	stk[++top]=u; instk[u]=1;
	for(int v : e[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(instk[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		int x=0; cnt++;
		while(u!=x){
			x=stk[top--]; instk[x]=0;
			nv[cnt]+=v[x];
			nw[cnt]+=w[x];
			scc[x]=cnt;
		}
	}
}

inline void dfs(int u){
	for(int i=nw[u];i<=m;i++) f[u][i]=nv[u];
	for(int v : ne[u]){
		dfs(v);
		for(int i=m;i>=nw[u];i--){
			for(int j=0;j<=i-nw[u];j++){
				f[u][i]=max(f[u][i],f[u][i-j]+f[v][j]);
			}
		}
	}
}

inline void qwq_(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++) cin>>v[i];
	for(int i=1;i<=n;i++){
		cin>>d[i];
		if(d[i]) e[d[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int u=1;u<=n;u++){
		for(int v : e[u]){
			if(scc[u]!=scc[v]){
				ne[scc[u]].push_back(scc[v]);
				din[scc[v]]++;
			}
		}
	}
	for(int i=1; i<=cnt; i++) {
		sort(ne[i].begin(), ne[i].end());
		ne[i].erase(unique(ne[i].begin(), ne[i].end()), ne[i].end());
  }
	for(int u=1;u<=cnt;u++){
		if(!din[u]) ne[0].push_back(u);
	}
	dfs(0);
	cout<<f[0][m];
	// // 求在∑w[i]<=m时的max∑v[i]
	// for(int i=1;i<=n;i++){
	// 	int x=install(i); // 考虑安装一个软件时，如果他有父亲，则必须安装所有的父亲。
	// 	for(int j=m;j>=x;j--){
	// 		// 考虑如果一个软件有儿子，则枚举安装不同儿子的最大价值

	// 	}
	// }
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