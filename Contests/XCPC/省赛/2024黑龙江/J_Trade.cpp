#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e3+9, M = 2e5+9, mod = 998244353; int t_ = 1;
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
int a[N][N], b[N][N], dist[N][N], f[N][N];
int dx[] = {1, 0};
int dy[] = {0, 1};

struct point{
	int x, y;
	bool operator<(const point &o) const{
		if (x != o.x) return x < o.x;
    return y < o.y;
	}
};

inline void bfs(int x, int y){
	memset(dist, 0x3f, sizeof dist);
	dist[x][y] = a[x][y] + b[x][y];
	priority_queue<pair<int, point>> q;
	q.push({-dist[x][y], {x, y}});

	while(q.size()){
		x = q.top().second.x;
		y = q.top().second.y;
		int k = -q.top().first;
		q.pop();
		if(k > dist[x][y]) continue;
		for(int i=0; i<2; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx > n || ny > m) continue;
			int nk = k + b[nx][ny];
			if(a[nx][ny] >= nk){
				if(nx == n || ny == m){
					cout << "YES\n";
					return;
				}
				if(nk >= dist[nx][ny]) continue;
				dist[nx][ny] = nk;
				q.push({-nk, {nx, ny}});
			}
		}
	}

	cout << "NO\n";
}

inline void qwq_(){
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> b[i][j];
		}
	}
	// f[1][1] = a[1][1] + b[1][1];
	// for(int i=2; i<=n; i++){
	// 	f[i][1] = f[i-1][1] + b[i][1];
	// }
	// for(int i=2; i<=m; i++){
	// 	f[1][i] = f[1][i-1] + b[1][i];
	// }
	// for(int i=2; i<=n; i++){
	// 	for(int j=2; j<=m; j++){
	// 		f[i][j] = b[i][j] + min(f[i-1][j], f[i][j-1]);
	// 	}
	// }
	bfs(1, 1);
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