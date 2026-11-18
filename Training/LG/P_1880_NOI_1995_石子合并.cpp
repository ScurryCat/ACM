#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 2e2+9, M = 2e5+9, mod = 998244353; int t_ = 1;
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

const int inf = 1e9;
int n;
int a[N], s[N], f1[N][N], f2[N][N];

inline void qwq_(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		a[n+i] = a[i];
	}
	for(int i=1; i<=n+n; i++){
		s[i] = s[i-1] + a[i];
	}
	for(int i=1; i<=n+n; i++){
		for(int j=1; j<=n+n; j++){
			if(i == j){
				f1[i][j] = 0;
			}
			else{
				f1[i][j] = inf;
				f2[i][j] = -inf;
			}
		} 
	}
	for(int len=2; len<=n; len++){
		for(int l=1; l+len-1<=n+n; l++){
			int r = l+len-1;
			for(int k=l; k<r; k++){
				f1[l][r] = min(f1[l][r], f1[l][k] + f1[k+1][r] + s[r] - s[l-1]);
				f2[l][r] = max(f2[l][r], f2[l][k] + f2[k+1][r] + s[r] - s[l-1]);
			}
		}
	}
	int ans1 = inf, ans2 = -inf;
	for(int i=1; i<=n; i++){
		ans1 = min(ans1, f1[i][i+n-1]);
		ans2 = max(ans2, f2[i][i+n-1]);
	}
	cout << ans1 << '\n' << ans2;
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