#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 500+9, M = 2e5+9, mod = 998244353; int t_ = 1;
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

int n, m, x, y;
int dis[N][N];
int dx[] = {1, 1, 2, -2, -1, -1, 2, -2};
int dy[] = {2, -2, 1, 1, 2, -2, -1, -1};

inline void bfs(int x, int y){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			dis[i][j] = -1;
		}
	}
	dis[x][y] = 0;
	queue<pair<int, int>> q;
	q.push({x, y});
	while(q.size()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0; i<8; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if(dis[nx][ny] != -1) continue;
			dis[nx][ny] = dis[x][y] + 1;
			q.push({nx, ny});
		}
	}
}

inline void qwq_(){
	cin >> n >> m >> x >> y;
	bfs(x, y);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cout << dis[i][j] << ' ';
		}
		cout << '\n';
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