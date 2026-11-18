#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 3e6+9, M = 2e5+9, mod = 998244353; int t_ = 1;
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

inline void solve1(){
	string s;
	ll cnt2 = 0, cnt20 = 0, cnt202 = 0, cnt2023 = 0;
	for(int i=1; i<=2023; i++){
			s += to_string(i);
	}
	for(int i=0; i<s.size(); i++){
		if(s[i] == '2'){
			cnt202 += cnt20;
			cnt2++;
		}
		if(s[i] == '0'){
			cnt20 += cnt2;
		}
		if(s[i] == '3'){
			cnt2023 += cnt202;
		}
	}
	cout << cnt2023;
}

int p[N], idx;
bool v[N];
//p*p*q*q
inline void ora(int n){
	for(int i=2; i<=n; i++){
		if(!v[i]) p[++idx] = i;
		for(int j=1; i*p[j]<=n; j++){
			v[i*p[j]] = 1;
			if(i % p[j] == 0) break;
		}
	}
}

inline void solve2(){
	// cout << pow(23333333333333, 0.25);
	// cout << sqrt(5833333333333) << '\n';
	ora(sqrt(5833333333333)+1);
	int ans = 0;
	map<ll, bool> vis;
	for(int i=1; i<=idx; i++){
		for(int j=i+1; j<=idx; j++){
			if(1ll * p[i] * p[j] > sqrt(23333333333333)+1) continue;
			ll x = 1ll * p[i] * p[i] * p[j] * p[j];
			if(x < 2333 || x > 23333333333333) continue;
			if(!vis[x]){
				ans++;
				vis[x] = 1;
			}
		}
	}
	cout << ans;
}

inline void qwq_(){
	char op; cin >> op;
	ll ans1 = 5484660609, ans2 = 947293;
	// if(op == 'A') solve1();
	// else solve2();
	if(op == 'A') cout << ans1;
	else cout << ans2;
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