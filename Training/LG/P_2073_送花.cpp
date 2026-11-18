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
	int p, s[2], c, w;
	ll cSize, wSize;
	void init(int pp, int cc, int ww){
		p = pp; c = cc; w = ww;
		wSize = w; cSize = c;
	}
}tr[N];
int root, idx;
int res1, res2;

inline void pushup(int x){
	tr[x].cSize = tr[tr[x].s[0]].cSize + tr[tr[x].s[1]].cSize + tr[x].c;
	tr[x].wSize = tr[tr[x].s[0]].wSize + tr[tr[x].s[1]].wSize + tr[x].w;
}

inline void rotate(int x){
	int y = tr[x].p, z = tr[y].p;
	int k = tr[y].s[1] == x;
	tr[y].s[k] = tr[x].s[k^1];
	tr[tr[x].s[k^1]].p = y;
	tr[x].s[k^1] = y;
	tr[y].p = x;
	tr[z].s[tr[z].s[1]==y] = x;
	tr[x].p = z;
	pushup(y); pushup(x);
}

inline void splay(int x, int k){
	while(tr[x].p != k){
		int y = tr[x].p, z = tr[y].p;
		if(z != k){
			(tr[y].s[0]==x) ^ (tr[z].s[0]==y) ? rotate(x) : rotate(y);
		}
		rotate(x);
	}
	if(k == 0) root = x;
}

inline void find(int c){
	int x = root;
	while(tr[x].c != c && tr[x].s[c > tr[x].c]){
		x = tr[x].s[c > tr[x].c];
	}
	splay(x, 0);
}

inline void insert(int c, int w){
	int x = root, p = 0;
	while(x && tr[x].c != c){
		p = x;
		x = tr[x].s[c > tr[x].c];
	}
	if(x) return;
	else{
		x = ++idx;
		tr[p].s[c > tr[p].c] = x;
		tr[x].init(p, c, w);
	}
	splay(x, 0);
}

inline int get_pre(int v){
	find(v);
	int x = root;
	if(tr[x].c < v) return x;
	x = tr[x].s[0];
	while(tr[x].s[1]) x = tr[x].s[1];
	splay(x, 0);
	return x;
}

inline int get_suc(int v){
	find(v);
	int x = root;
	if(tr[x].c > v) return x;
	x = tr[x].s[1];
	while(tr[x].s[0]) x = tr[x].s[0];
	splay(x, 0);
	return x;
}

inline void del_exp(){
	int c = tr[get_pre(1e9)].c;
	if(c == -1e9) return;
	int pre = get_pre(c);
	int suc = get_suc(c);
	splay(pre, 0);
	splay(suc, pre);
	tr[suc].s[0] = 0;
	splay(suc, 0);
}

inline void del_che(){
	int c = tr[get_suc(-1e9)].c;
	if(c == 1e9) return;
	int pre = get_pre(c);
	int suc = get_suc(c);
	splay(pre, 0);
	splay(suc, pre);
	tr[suc].s[0] = 0;
	splay(suc, 0);
}

inline void qwq_(){
	insert(-1e9, 0); insert(1e9, 0);
	while(1){
		int opt; cin >> opt;
		switch(opt){
			case -1:{
				cout << tr[root].wSize << ' ' << tr[root].cSize;
				return;
			}
			case 1:{
				int w, c;
				cin >> w >> c;
				insert(c, w);
				break;
			}
			case 2:{
				del_exp();
				break;
			}
			case 3:{
				del_che();
				break;
			}
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