#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 2e5+9, mod = 998244353;
using ll = long long; using ld = long double; using i128 = __int128; int t_ = 1;

#ifndef ONLINE_JUDGE
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {os << "["; for(int i=0; i<v.size(); i++) os << (i?", ":"") << v[i]; return os << "]";}
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {return os << "(" << p.first << ", " << p.second << ")";}
void debug_out(vector<string> names, int idx) { cerr << endl;} template <typename Head, typename... Tail>
void debug_out(vector<string> names, int idx, Head H, Tail... T) {if (idx > 0) cerr << ", ";string name = names[idx]; name.erase(0, name.find_first_not_of(' ')); name.erase(name.find_last_not_of(' ') + 1);cerr << name << "=" << H;debug_out(names, idx + 1, T...);}
#define debug(...) {string _s = #__VA_ARGS__, _tmp; vector<string> _names; int _p = 0;for (char c : _s) {if (c == '(' || c == '{') _p++;else if (c == ')' || c == '}') _p--;else if (c == ',' && _p == 0) { _names.push_back(_tmp); _tmp = "";continue;}_tmp += c;} _names.push_back(_tmp);cerr << "T" << t_<< " Line " << __LINE__ << ": "; debug_out(_names, 0, __VA_ARGS__);}
#else
#define debug(...)
#endif

ll n,a[N],l1[N],r1[N],l2[N],r2[N],tr[N];

inline ll lowbit(ll x){return x&-x;}

inline void update(int x,int k){
	while(x<=n){
		tr[x]+=k;
		x+=lowbit(x);
	}
}

inline ll query(int x){
	ll r=0;
	while(x>=1){
		r+=tr[x];
		x-=lowbit(x);
	}
	return r;
}

inline void qwq_(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		l2[i]=query(a[i]-1);
		l1[i]=i-1-l2[i];
		update(a[i],1);
	}
	memset(tr,0,sizeof tr);
	for(int i=n;i>=1;i--){
		r2[i]=query(a[i]-1);
		r1[i]=n-i-r2[i];
		update(a[i],1);
	}
	ll a=0,b=0;
	for(int i=1;i<=n;i++){
		a+=l1[i]*r1[i];
		b+=l2[i]*r2[i];
	}
	cout<<a<<' '<<b;
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