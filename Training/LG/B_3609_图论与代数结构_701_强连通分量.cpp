#include <bits/stdc++.h>
using namespace std;

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

int n,m;
int h[N],to[N],ne[N],tot=1;
int stk[N],instk[N],top;
int dfn[N],low[N],idx;
vector<int> scc[N];
int cnt;

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
	if(dfn[u]==low[u]){
		int v=0; cnt++;
		while(u!=v){
			v=stk[top--]; instk[v]=0;
			scc[cnt].push_back(v);
		}
	}
}

bool cmp(vector<int> &x,vector<int> &y){
	return x[0]<y[0];
}

inline void qwq_(){
	cin>>n>>m;
	while(m--){
		int u,v; cin>>u>>v;
		add(u,v);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	cout<<cnt<<'\n';
	for(int i=cnt;i>=1;i--){
		sort(scc[i].begin(),scc[i].end());
	}
	sort(scc+1,scc+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		for(int u : scc[i]){
			cout<<u<<' ';
		}
		cout<<'\n';
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