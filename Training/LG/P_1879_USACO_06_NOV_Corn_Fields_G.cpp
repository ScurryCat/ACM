#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e5+9, M = 2e5+9, mod = 1e8; int t_ = 1;
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
int g[13];
int s[13][1<<12], cnt[13];
int f[13][1<<12];	// f[i][j] 表示 第i行的第j种合法状态
									// f[i][j] = ∑f[i-1][s[i-1]];

inline void qwq_(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			int x; cin >> x;
			g[i] = (g[i]<<1) + x;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=0; j<(1<<m); j++){
			if((j & (j>>1)) || (j & g[i]) != j) continue;
			s[i][++cnt[i]] = j;
		}
	}

	// for(int i=1; i<=n; i++){
	// 	cout << i << ':' << '\n';
	// 	for(int j=1; j<=cnt[i]; j++){
	// 		print(s[i][j]);
	// 	}
	// }

	for(int i=1; i<=cnt[1]; i++){
		f[1][i] = 1;
	}

	for(int i=2; i<=n; i++){
		for(int j=1; j<=cnt[i]; j++){
			for(int k=1; k<=cnt[i-1]; k++){
				if(s[i][j] & s[i-1][k]) continue;
				f[i][j] = (f[i][j] + f[i-1][k]) % mod;
			}
		}
	}
	
	for(int i=1; i<=cnt[n]; i++){
		res = (res + f[n][i]) % mod;
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