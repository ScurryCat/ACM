#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e5+9, mod = 998244353;
using ll = long long; using ld = long double; using i128 = __int128; int t_ = 1;
inline ll read(){ll r=0,f=1; char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-') f*=-1; ch=getchar();}while('0'<=ch&&ch<='9'){r=(r<<1)+(r<<3)+ch-'0'; ch=getchar();}return r*f;}

#ifndef ONLINE_JUDGE
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {os << "["; for(int i=0; i<v.size(); i++) os << (i?", ":"") << v[i]; return os << "]";}
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {return os << "(" << p.first << ", " << p.second << ")";}
void debug_out(vector<string> names, int idx) { cerr << endl;} template <typename Head, typename... Tail>
void debug_out(vector<string> names, int idx, Head H, Tail... T) {if (idx > 0) cerr << ", ";string name = names[idx]; name.erase(0, name.find_first_not_of(' ')); name.erase(name.find_last_not_of(' ') + 1);cerr << name << "=" << H;debug_out(names, idx + 1, T...);}
#define debug(...) {string _s = #__VA_ARGS__, _tmp; vector<string> _names; int _p = 0;for (char c : _s) {if (c == '(' || c == '{') _p++;else if (c == ')' || c == '}') _p--;else if (c == ',' && _p == 0) { _names.push_back(_tmp); _tmp = "";continue;}_tmp += c;} _names.push_back(_tmp);cerr << "T" << t_<< " Line " << __LINE__ << ": "; debug_out(_names, 0, __VA_ARGS__);}
#else
#define debug(...)
#endif

int n,m;

void calc(vector<int> &a,int b){
	vector<int> r=a;
	r.resize(a.size()+10);
	for(int i=0;i<a.size();i++){
		r[i] += a[i]*b;
		r[i+1] += r[i]/10;
		r[i] %= 10;
	}
	while(r.back()==0) r.pop_back();
	while(r.back()>=10){
		int x=r.back()/10;
		r.back()%=10;
		r.push_back(x);
	}
	debug(r);
	a=r;
}

inline void qwq_(){
	ll n; cin>>n;
	vector<int> ans(1,1);
	for(int i=2;i<=n;i++){
		calc(ans,i);
	}
	for(int i=ans.size()-1;~i;i--) cout<<ans[i];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--){
		qwq_();
		++t_;
	}
	return 0;
}