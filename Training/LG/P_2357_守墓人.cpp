#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 2e5+9, M = 2e5+9, mod = 998244353; int t_ = 1;
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

int n, q;
ll t1[N], t2[N];
// d[i], i*d[i]

int lowbit(int x){
	return x & -x;
}

void add(int x, ll k){
	for(int i=x; i<=n; i+=lowbit(i)){
		t1[i] += k;
		t2[i] += k * x;
	}
}

void radd(int x, int y, ll k){
	add(x, k); add(y+1, -k);
}

ll query(int x){
	ll r = 0;
	for(int i=x; i>=1; i-=lowbit(i)){
		r += (x + 1) * t1[i] - t2[i];
	}
	return r;
}

ll rquery(int x, int y){
	return query(y) - query(x - 1);
}

inline void qwq_(){
	cin >> n >> q;
	for(int i=1; i<=n; i++){
		ll x; cin >> x;
		radd(i, i, x);
	}
	while(q--){
		int op; cin >> op;
		if(op == 1){
			ll x, y, k;
			cin >> x >> y >> k;
			radd(x, y, k);
		}
		else if(op == 2){
			ll k; cin >> k;
			radd(1, 1, k);
		}
		else if(op == 3){
			ll k; cin >> k;
			radd(1, 1, -k);
		}
		else if(op == 4){
			int x, y;
			cin >> x >> y;
			cout << rquery(x, y) << '\n';
		}
		else if(op == 5){
			cout << rquery(1, 1) << '\n';
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