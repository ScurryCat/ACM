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

struct node{
	int p, s[2], v, cnt, size;
	void init(int pp, int vv){
		p = pp; v = vv;
		size = cnt = 1;
	}
}tr[N];
int root, idx;

inline void pushup(int x){
	tr[x].size = tr[tr[x].s[0]].size + tr[tr[x].s[1]].size + tr[x].cnt;
}

inline void rotate(int x){
	int y = tr[x].p, z = tr[y].p;
	int k = (tr[y].s[1] == x);
	tr[y].s[k] = tr[x].s[k^1];
	tr[tr[x].s[k^1]].p = y;
	tr[x].s[k^1] = y;
	tr[y].p = x;
	tr[z].s[tr[z].s[1] == y] = x;
	tr[x].p = z;
	pushup(y); pushup(x);
}

inline void splay(int x, int k){
	while(tr[x].p != k){
		int y = tr[x].p, z = tr[y].p;
		if(z != k){
			(tr[y].s[0] == x) ^ (tr[z].s[0] == y) ? rotate(x) : rotate(y);
		}
		rotate(x);
	}
	if(k == 0) root = x;
}

inline void find(int v){
	int x = root;
	while(tr[x].v != v && tr[x].s[v > tr[x].v]){
		x = tr[x].s[v > tr[x].v];
	}
	splay(x, 0);
}

inline void insert(int v){
	int x = root, p = 0;
	while(x && tr[x].v != v){
		p = x;
		x = tr[x].s[v > tr[x].v];
	}
	if(x) tr[x].cnt++;
	else{
		x = ++idx;
		tr[p].s[v > tr[p].v] = x;
		tr[x].init(p, v);
	}
	splay(x, 0);
}

inline int get_pre(int v){
	find(v);
	if(tr[root].v < v) return root;
	int x = tr[root].s[0];
	while(tr[x].s[1]) x = tr[x].s[1];
	splay(x, 0);
	return x;
}

inline int get_suc(int v){
	find(v);
	if(tr[root].v > v) return root;
	int x = tr[root].s[1];
	while(tr[x].s[0]) x = tr[x].s[0];
	splay(x, 0);
	return x;
}

inline void del(int v){
	int pre = get_pre(v);
	int suc = get_suc(v);
	splay(pre, 0);
	splay(suc, pre);
	int d = tr[suc].s[0];
	if(tr[d].cnt > 1){
		tr[d].cnt--;
		splay(d, 0);
	}
	else{
		tr[suc].s[0] = 0;
		splay(suc, 0);
	}
}

inline int get_rank(int v){
	insert(v);
	int r = tr[tr[root].s[0]].size;
	del(v);
	return r;
}

inline int get_val(int k){
	int x = root;
	while(1){
		int y = tr[x].s[0];
		if(tr[y].size + tr[x].cnt < k){
			k -= tr[y].size + tr[x].cnt;
			x = tr[x].s[1];
		}
		else{
			if(tr[y].size >= k) x = y;
			else break;
		}
	}
	splay(x, 0);
	return tr[x].v;
}

inline void qwq_(){
	int q; cin >> q;
	insert(-2147483647); insert(2147483647);
	while(q--){
		int opt, x;
		cin >> opt >> x;
		switch(opt){
			case 1: cout << get_rank(x) << '\n'; break;
			case 2: cout << get_val(x+1) << '\n'; break;
			case 3: cout << tr[get_pre(x)].v << '\n'; break;
			case 4: cout << tr[get_suc(x)].v << '\n'; break;
			case 5: insert(x); break;
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