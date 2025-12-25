#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e5+9, M = 4e5+9, mod = 998244353; int t_ = 1;
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
vector<int> e[N];
int h[N],to[M],ne[M],tot=1;
int dfn[N],low[N],idx;
int stk[N],instk[N],top;
int scc[N],siz[N],cnt;
int d[N+N];

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
		if(instk[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		int v=0; cnt++;
		while(u!=v){
			v=stk[top--]; instk[v]=0;
			siz[cnt]++;
			scc[v]=cnt;
		}
	}
}

inline void dijkstra(int s){
	priority_queue<pair<int,int>> q;
	q.push({0,s});
	while(q.size()){
		int u=q.top().second;
		int uu=(u>cnt?u-cnt:u);
		for(int v : e[uu]){
			if(v<=cnt){
				if(d[v]>d[cnt+u]){
					d[cnt+u]=d[v];
					q.push({d[cnt+u],cnt+u});
				}
			}
			if(d[v]<d[u]+siz[u]){
				d[v]=d[u]+siz[u];
				q.push({d[v],v});
			}
		}
	}
}

// 从1出发遍历全图随后返回1，最多走一次反边，问最多能走多少块
// 考虑tarjan缩点，建立新的分层图，起点终点都应该是1所在的强连通分量。

inline void qwq_(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v; cin>>u>>v;
		add(u,v); add(v,u);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int u=1;u<=n;u++){
		for(int i=h[u];i;i=ne[i]){
			int v=to[i];
			if(scc[u]!=scc[v]){
				e[scc[u]].push_back(scc[v]);
			}
		}
	}
	dijkstra(scc[1]);
	cout<<min(d[1],d[1+n]);
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