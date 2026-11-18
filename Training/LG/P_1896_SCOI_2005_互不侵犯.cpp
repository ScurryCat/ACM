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

int n, k;
// f[i][j][a] 表示前i行放了j个国王，第i行的第a个状态的方案树 
int s[1<<11], num[1<<11], cnt;
ll f[11][11*11][1<<11];
ll res;

inline void print(int x){
	cout << x << ':' << ' ';
	for(int i=0; i<n; i++){
		cout << ((x>>i) & 1) ? 1 : 0;
	}
	cout << '\n';
}

inline void qwq_(){
	cin >> n >> k;
	for(int i=0; i<(1<<n); i++){
		if(!(i & (i>>1))){
			s[++cnt] = i;
		}
	}

	for(int i=1; i<=cnt; i++){
		int x = s[i], y = 0;
		while(x){
			if(x & 1) y++;
			x >>= 1;
		}
		num[i] = y;
		// print(s[i]);
	}

	for(int i=1; i<=cnt; i++){
		f[1][num[i]][i] = 1;
	}

	for(int i=2; i<=n; i++){
		for(int j=0; j<=k; j++){
			for(int a=1; a<=cnt; a++){
				if(j < num[a]) continue;
				for(int b=1; b<=cnt; b++){
					int x = s[a], y = s[b];
					if(!(x & y) && !(x & (y<<1)) && !(x & (y>>1))){
						f[i][j][a] += f[i-1][j-num[a]][b];
					}
				}
			}
		}
	}
	for(int i=1; i<=cnt; i++){
		res += f[n][k][i];
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