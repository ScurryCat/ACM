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

struct SegmentTree{
	#define lc p << 1
	#define rc p << 1 | 1

	int w[N];

	struct node{
		int l, r;
		ll add, sum;
	}tr[N<<2];

	void pushup(int p){
		tr[p].sum = tr[lc].sum + tr[rc].sum;
	}

	void pushdown(int p){
		if(tr[p].add){
			tr[lc].sum += (tr[lc].r - tr[lc].l + 1) * tr[p].add;
			tr[rc].sum += (tr[rc].r - tr[rc].l + 1) * tr[p].add;
			tr[lc].add += tr[p].add;
			tr[rc].add += tr[p].add;
			tr[p].add = 0;
		}
	}

	void build(int p, int l, int r){
		tr[p] = {l, r, 0, w[l]};
		if(l == r) return;
		int m = l + r >> 1;
		build(lc, l, m);
		build(rc, m+1, r);
		pushup(p);
	}

	void update(int p, int x, int k){
		if(tr[p].r < x || tr[p].l > x) return;
		if(x == tr[p].l && tr[p].r == x){
			tr[p].sum += (tr[p].r - tr[p].l + 1) * k;
			tr[p].add += k;
			return;
		}
		pushdown(p);
		update(lc, x, k);
		update(rc, x, k);
		pushup(p);
	}

	ll query(int p, int l, int r){
		if(tr[p].r < l || tr[p].l > r) return 0;
		if(l <= tr[p].l && tr[p].r <= r){
			return tr[p].sum;
		}
		ll res = 0;
		pushdown(p);
		res += query(lc, l, r);
		res += query(rc, l, r);
		return res;
	}
};

SegmentTree seg;

inline void qwq_(){
	int n, q;
	cin >> n >> q;
	memset(seg.w, 0, sizeof seg.w);
	seg.build(1, 1, n);
	while(q--){
		char op;
		int x, y;
		cin >> op >> x >> y;
		if(op == 'x'){
			seg.update(1, x, y);
		}
		else{
			cout << seg.query(1, x, y) << '\n';
		}
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