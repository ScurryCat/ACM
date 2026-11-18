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

ll fac[59];

inline void qwq_(){
	int n; cin >> n;
	vector<int> a(n+1);
	ll ans = 0, cnt = 0, x = 0, y = 0;
	for(int i=0; i<=n; i++){
		cin >> a[i];
		cnt += a[i];
	}
	int m = cnt/n;
	for(int i=1; i<=n; i++){
		if(a[i]<=m) x++;
		else if(a[i]>m+1) y++;
	}
	if(y > 0) cout << "0\n";
	else{
		m = n - cnt % n;
		if(x < m) cout << "0\n";
		else{
			ans = fac[cnt%n];
			for(int i=0; i<m; i++) ans = (ans * (x-i)) % mod;
			cout << ans << '\n';
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	fac[0]=1;
	for(int i=1;i<=50;i++) fac[i] = fac[i-1] * i % mod;
	int yyy = 1;
	cin >> yyy;
	while(yyy--){
		qwq_();
		t_+=1;
	}
	return 0;
}