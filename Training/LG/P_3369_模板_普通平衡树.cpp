#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

struct node{
	int s[2];
	int p;
	int v;
	int cnt;
	int size;
	void init(int pp, int vv){
		p = pp;
		v = vv;
		cnt = size = 1;
	}
}tr[N];
int root, idx;

inline void pushup(int x){
	tr[x].size = tr[tr[x].s[0]].size + tr[tr[x].s[1]].size + tr[x].cnt;
}

inline void rotate(int x){
	int y = tr[x].p, z = tr[y].p;
	int k = tr[y].s[1] == x;
	tr[y].s[k] = tr[x].s[k^1];
	tr[tr[x].s[k^1]].p = y;
	tr[x].s[k^1] = y;
	tr[y].p = x;
	tr[z].s[y == tr[z].s[1]] = x;
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

inline void find(int v){
	int x = root;
	while(tr[x].v!=v && tr[x].s[v>tr[x].v]){
		x = tr[x].s[v>tr[x].v];
	}
	splay(x, 0);
}

inline void insert(int v){
	int x = root, p = 0;
	while(x && tr[x].v!=v){
		p = x;
		x = tr[x].s[v>tr[x].v];
	}
	if(x) tr[x].cnt++;
	else{
		x = ++idx;
		tr[p].s[v>tr[p].v] = x;
		tr[x].init(p, v);
	}
	splay(x, 0);
}

inline int get_pre(int v){
	find(v);
	int x = root;
	if(tr[x].v < v) return x;
	x = tr[x].s[0];
	while(tr[x].s[1]) x = tr[x].s[1];
	return x; 
}

inline int get_suc(int v){
	find(v);
	int x = root;
	if(tr[x].v > v) return x;
	x = tr[x].s[1];
	while(tr[x].s[0]) x = tr[x].s[0];
	return x;
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
			if(tr[y].size >= k) x = tr[x].s[0];
			else break;
		}
	}
	splay(x, 0);
	return tr[x].v;
}

inline void del(int v){
	int pre = get_pre(v);
	int suc = get_suc(v);
	splay(pre, 0); splay(suc, pre);
	int del = tr[suc].s[0];
	if(tr[del].cnt > 1){
		tr[del].cnt--;
		splay(del, 0);
	}
	else{
		tr[suc].s[0] = 0;
		splay(suc, 0);
	}
}

int get_rank(int v) { //数值v排名
 // find(v);
 // return tr[tr[root].s[0]].size;
	insert(v);
	int res = tr[tr[root].s[0]].size;
	del(v);
	return res;
 }

void qwq_(){
	insert(-1e9); insert(1e9);
	int n; cin >> n;
	while(n--){
		int opt, x;
		cin >> opt >> x;
		switch(opt){
			case 1: insert(x); break;
			case 2: del(x); break;
			case 3: cout << get_rank(x) << '\n'; break;
			case 4: cout << get_val(x+1) << '\n'; break;
			case 5: cout << tr[get_pre(x)].v << '\n'; break;
			case 6: cout << tr[get_suc(x)].v << '\n'; break;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}