#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e5+9, M = 2e5+9, mod = 998244353; int t_ = 1;
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

int n, m1, m2, r;
vector<int> s, ns;	
vector<int> mv;	// mv存储合法转移方式
int ok[1<<15];	// ok存储合法状态
int f[1<<15];	// f存储每个状态最短路的方案数
int dep[N];

inline int lowbit(int x){
	return x&-x;
}

inline int check(int x, int a){
	return (x>>(a-1)) & 1;
}

inline void print(int x){
	for(int i=n-1;~i;i--){
		cout<<((x>>i)&1);
	}
	cout<<'\n'; 
}

inline void bfs(int u){
	for(int i=0;i<(1<<n);i++) dep[i] = -1;
	dep[u]=0;
	f[u]=1;

	queue<int> q;
	q.push(u);

	while(q.size()){
		u=q.front();
		q.pop();
		for(int x : mv){
			int v = u ^ x;
			if(ok[v]){
				if(dep[v] == -1){
					dep[v] = dep[u] + 1;
					f[v] = f[u];
					q.push(v);
				}
				else if(dep[v] == dep[u] + 1){
					f[v] = (f[v] + f[u]);
				}
			}
		}
	}
}

inline void qwq_(){
	cin>>n>>m1>>m2>>r;

	for(int i=0;i<(1<<n);i++){
		int x=i,y=0;
		s.push_back(x);
		while(x){
			x-=lowbit(x);
			y++;
		}
		if(y<=r){
			mv.push_back(i);
		}
	}

	if(m1){
		for(int i=1;i<=m1;i++){
			int a,b; cin>>a>>b;
			for(int i=s.size()-1;~i;i--){
				int x = s[i];
				if(check(x,a) != check(x,b)){
					s.erase(s.begin()+i);
				}
			}
		}
	}

	if(m2){
		for(int i=1;i<=m2;i++){
			int a,b,c;
			cin>>a>>b>>c;
			for(int x : s){
				if((check(x,a)==check(x,b)) || (check(x,a)==check(x,c))){
					ns.push_back(x);
				}
			}
			s = ns;
			ns.clear();
		}
	}
	
	for(int x : s) ok[x] = 1;

	bfs(0);

	int t = (1<<n)-1;
	cout << dep[t] << ' ' << f[t];

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