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

int n, m, res;
int g[101], s[101][1<<10], cnt[101], num[1<<10];
int f[101][1<<10][1<<10]; // f[i][j][k] 表示第i行第j个状态,第i-1行第k个状态时的最多共存数
									 				// f[i][j][k] = max(f[i-1][b][c]) + num[s[i][a]];

inline void print(int x){
	cout << x << ':';
	for(int i=m-1; ~i; i--){
		cout << ((x>>i) & 1) ? 1 : 0;
	}
	cout << '\n';
}

inline int lowbit(int x){
	return x & -x;
}

inline void qwq_(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			char x; cin >> x;
			g[i] = (g[i]<<1) + ((x=='P') ? 1 : 0);
		}
	}

	for(int i=1; i<=n; i++){
		for(int j=0; j<(1<<m); j++){
			if((j&(j>>1)) || (j&(j>>2))) continue;
			if((j & g[i]) != j) continue;
			s[i][++cnt[i]] = j;
		}
	}

	for(int i=0; i<(1<<m); i++){
		int x = i, r = 0;
		while(x){
			x -= lowbit(x);
			r++;
		}
		num[i] = r;
	}

	for(int a=1; a<=cnt[1]; a++){
		f[1][a][0] = num[s[1][a]];
	}

	for(int a=1; a<=cnt[2]; a++){
		for(int b=1; b<=cnt[1]; b++){
			int x = s[2][a], y = s[1][b];
			if(x&y) continue;
			f[2][a][b] = max(f[2][a][b], f[1][b][0] + num[s[2][a]]);
		}
	}

	for(int i=3; i<=n; i++){
		for(int a=1; a<=cnt[i]; a++){
			int x = s[i][a];
			for(int b=1; b<=cnt[i-1]; b++){
				int y = s[i-1][b];
				for(int c=1; c<=cnt[i-2]; c++){
					int z = s[i-2][c];
					if((x&y) || (y&z) || (z&x)) continue;
					f[i][a][b] = max(f[i][a][b], f[i-1][b][c] + num[s[i][a]]);
				}
			}
		}
	}

	for(int i=1; i<=cnt[n]; i++){
		for(int j=0; j<(1<<m); j++){
			res = max(res, f[n][i][j]);
		}
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