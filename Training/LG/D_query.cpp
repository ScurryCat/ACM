#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e6+9, M = 2e5+9, mod = 998244353; int t_ = 1;
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

int B;
struct Q{
	int l, r, id;
	bool operator<(const Q &q) const{
		if(l / B != q.l / B) return l < q.l;
		if((l / B) & 1) return r < q.r;
		return r > q.r;
	}
}q[N];

int n, m, l = 1, r, sum;
int a[N], ans[N], cnt[N];

inline void add(int x){
	if(++cnt[x] == 1) sum++;
}

inline void del(int x){
	if(--cnt[x] == 0) sum--;
}

inline void qwq_(){
	cin >> n;
	B = sqrt(n);
	for(int i=1; i<=n; i++) cin >> a[i];
	cin >> m;
	for(int i=1; i<=m; i++) cin >> q[i].l >> q[i].r, q[i].id = i;
	sort(q+1, q+m+1);
	for(int i=1; i<=m; i++){
		while(l > q[i].l) add(a[--l]);
		while(r < q[i].r) add(a[++r]);
		while(l < q[i].l) del(a[l++]);
		while(r > q[i].r) del(a[r--]);
		ans[q[i].id] = sum;
	}
	for(int i=1; i<=m; i++) cout << ans[i] << '\n';
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