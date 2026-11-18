#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e4+9, M = 2e5+9, mod = 998244353; int t_ = 1;
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

int n, m;
int res, ans[N][5];
int w[N], vis[N];
vector<int> e[N];

// inline void dfs(int u, ll r, int t){
// 	res = max(res, r);
// 	if(t == 5 || t == n) return;
// 	if(r <= ans[u][t]) return;
// 	ans[u][t] = r;
// 	for(int v : e[u]){
// 		if(vis[v]) continue;
// 		vis[v] = 1;
// 		dfs(v, r+w[v], t+1);
// 		vis[v] = 0;
// 	}
// }

// inline void dfs(int u, ll r, int t){
// 	res = max(res, r);
// 	if(t == 5 || t == n) return;

// 	int cnt = 0;
// 	for(int v : e[u]){
// 		if(vis[v]) continue;
// 		vis[v] = 1;
// 		cnt++;
// 		dfs(v, r+w[v], t+1);
// 		vis[v] = 0;
// 		if(cnt == 4) break;
// 	}
// }

inline bool cmp(int x, int y){
	return w[x] > w[y];
}

inline void qwq_(){
	cin>>n>>m;

	for(int i=1; i<=n; i++){
		cin >> w[i];
	}

	for(int i=1; i<=m; i++){
		int u, v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	for(int i=1; i<=n; i++){
		sort(e[i].begin(), e[i].end(), cmp);
	}

	// for(int i=1; i<=n; i++){
	// 	vis[i] = 1;
	// 	dfs(i, w[i], 1);
	// 	vis[i] = 0;
	// }

	for(int b=1; b<=n; b++){
		if(vis[b]) continue;
		res = max(res, w[b]);
		vis[b] = 1;
		for(int c : e[b]){
			if(vis[c]) continue;
			res = max(res, w[b] + w[c]);
			vis[c] = 1;
			for(int d : e[c]){
				if(vis[d]) continue;
				res = max(res, w[b] + w[c] + w[d]);
				vis[d] = 1;
				int l=0, r=0;
				for(int a : e[b]){
					if(vis[a]) continue;
					l = a;
					vis[l] = 1;
					break;
				}
				for(int a : e[d]){
					if(vis[a]) continue;
					r = a;
					vis[r] = 1;
					break;
				}
				res = max(res, w[l] + w[r] + w[b] + w[c] + w[d]);
				l = r = vis[l] = vis[r] = 0;

				for(int a : e[d]){
					if(vis[a]) continue;
					r = a;
					vis[r] = 1;
					break;
				}
				for(int a : e[b]){
					if(vis[a]) continue;
					l = a;
					vis[l] = 1;
					break;
				}
				res = max(res, w[l] + w[r] + w[b] + w[c] + w[d]);
				vis[d] = vis[l] = vis[r] = 0;
			}
			vis[c] = 0;
		}
		vis[b] = 0;
	}

	cout << res;
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