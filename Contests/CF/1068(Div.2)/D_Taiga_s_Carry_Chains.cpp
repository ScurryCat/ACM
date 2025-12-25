#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e5+9, mod = 998244353;
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

ll lowbit(ll x){
	return x&-x;
}

inline void qwq_(){
	ll n,k; cin>>n>>k;
	int ans=0;
	while(k--){
		ll x=n;
		ll y=lowbit(n);
		int cnt=0;
		debug(x,y);
		for(int i=0;i<=30;i++){
			if((x&(y<<i))) cnt++;
			else break;
			debug(x,(1<<i),cnt);
		}
		ans+=cnt;
		debug(ans,cnt);
		n+=lowbit(n);
		for(int i=1;i<=31;i++) if(n==(1<<i)) break;
	}
	if(~k) ans+=k;
	cout<<ans<<'\n';
	// debug(lowbit(n));
	// n+=lowbit(n);
	
	// debug(lowbit(n));
	// n+=lowbit(n);
	
	// vector<int> a;
	// while(n){
	// 	a.push_back(n&1);
	// 	n>>=1;
	// }
	// reverse(a.begin(),a.end());
	// for(int i=0;i<a.size();i++) cout<<a[i];cout<<'\n';
	// debug(a);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--){
		qwq_();
		t_+=1;
	}
	return 0;
}