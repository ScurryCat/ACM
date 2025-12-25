#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 2e5+9, mod = 998244353;
using ll = long long; using ld = long double; using i128 = __int128; int t_ = 1;
inline ll read(){ll r=0,f=1; char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-') f*=-1; ch=getchar();}while('0'<=ch&&ch<='9'){r=(r<<1)+(r<<3)+ch-'0'; ch=getchar();}return r*f;}

#ifndef ONLINE_JUDGE
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {os << "["; for(int i=0; i<v.size(); i++) os << (i?", ":"") << v[i]; return os << "]";}
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {return os << "(" << p.first << ", " << p.second << ")";}
void debug_out(vector<string> names, int idx) { cerr << endl;} template <typename Head, typename... Tail>
void debug_out(vector<string> names, int idx, Head H, Tail... T) {if (idx > 0) cerr << ", ";string name = names[idx]; name.erase(0, name.find_first_not_of(' ')); name.erase(name.find_last_not_of(' ') + 1);cerr << name << "=" << H;debug_out(names, idx + 1, T...);}
#define debug(...) {string _s = #__VA_ARGS__, _t; vector<string> _n; int _p = 0;for (char c : _s) {if (c == '(' || c == '{') _p++;else if (c == ')' || c == '}') _p--;else if (c == ',' && _p == 0) { _n.push_back(_t); _t = "";continue;}_t += c;} _n.push_back(_t);cerr << "T" << t_<< " Line " << __LINE__ << ": "; debug_out(_n, 0, __VA_ARGS__);}
#else
#define debug(...)
#endif

int vis[N];
int n,k;

inline bool bfs(int u,vector<int> a,vector<int> e[]){
	memset(vis,0,sizeof vis);
	queue<int> q,p;
	p.push(u);
	vis[u]=1;
	for(int i=1;i<=k;i++){
		q.push(a[i]);
		vis[a[i]]=2;
	}
	while(1){
		queue<int> qq;
		while(q.size()){
			u=q.front(); q.pop();
			for(int v : e[u]){
				if(vis[v]==2) continue;
				vis[v]=2;
				qq.push(v);
			}
		}
		q=qq;
		queue<int> pp;
		while(p.size()){
			u=p.front(); p.pop();
			if(u!=1 && e[u].size()==1) return 1;
			for(int v : e[u]){
				if(vis[v]) continue;
				vis[v]=1;
				pp.push(v);
			}
		}
		p=pp;
		if(p.empty()) return 0;
	}
}

inline void qwq_(){
	cin>>n>>k;
	vector<int> a(k+1), e[n+1];
	for(int i=1;i<=k;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}	
	if(bfs(1,a,e)) cout<<"YES\n";
	else cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--){
		qwq_();
		t_++;
	}
	return 0;
}