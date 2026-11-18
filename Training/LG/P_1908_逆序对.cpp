#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 5e5+9, M = 2e5+9, mod = 998244353; int t_ = 1;
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

int n;
ll ans;

// int a[N], b[N];
// void mergesort(int l, int r){
// 	if(l == r) return;
// 	int m = l + r >> 1;
// 	int i = l, j = m + 1, k = l;
// 	mergesort(l, m);
// 	mergesort(m + 1, r);
// 	while(i <= m && j <= r){
// 		if(a[i] <= a[j]) b[k++] = a[i++];
// 		else b[k++] = a[j++], ans += m - i + 1;
// 	}
// 	while(i <= m) b[k++] = a[i++];
// 	while(j <= r) b[k++] = a[j++];
// 	for(int ii=l; ii<=r; ii++){
// 		a[ii] = b[ii];
// 	}
// }

// inline void qwq_(){
// 	cin >> n;
// 	for(int i=1; i<=n; i++) cin >> a[i];
// 	mergesort(1, n);
// 	cout << ans;
// }

inline int lowbit(int x){
	return x & -x;
}

ll cnt[N];

inline void add(int x, int k){
	while(x <= n) cnt[x] += k, x += lowbit(x);
}

inline ll query(int x){
	ll r = 0;
	while(x >= 1) r += cnt[x], x -= lowbit(x);
	return r;
}

inline void qwq_(){
	cin >> n;
	vector<int> a(n), b;
	for(int &x : a) cin >> x;
	b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for(int i=0; i<n; i++){
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
		ans += query(i) - query(a[i]);
		add(a[i], 1);
	}
	cout << ans;
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