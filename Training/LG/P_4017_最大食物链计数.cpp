#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 5e3+9, M = 5e5+9, mod = 80112002; int t_ = 1;
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
int h[N],to[M],ne[M],tot=1;
int din[N],dout[N],cnt[N]; // cnt[v] = cnt[v]+cnt[u]

inline void add(int u,int v){
	to[++tot]=v; ne[tot]=h[u]; h[u]=tot;
}

inline void qwq_(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v; cin>>u>>v;
		add(u,v);
		din[v]++;dout[u]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(din[i]) continue;
		cnt[i]=1;
		q.push(i);
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=h[u];i;i=ne[i]){
			int v=to[i];
			din[v]--;
			cnt[v] = (cnt[v]+cnt[u]) % mod;
			if(din[v]==0) q.push(v);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(dout[i]) continue;
		ans = (ans+cnt[i]) % mod;
	}
	cout<<ans;
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