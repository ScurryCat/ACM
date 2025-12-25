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

int n,m,ans;
int v[N],w[N],q[N],f[N];
vector<int> e[N];

inline void qwq_(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>v[i]>>w[i]>>q[i]; // 价格、重要度、主件
		if(q[i]) e[q[i]].push_back(i);
	}
	// 目标：在不超过n的基础下，保证∑v[i]*w[i]最大，若要购买i，则q[i]也必须购买
	for(int i=1;i<=m;i++){ // f[i]表示i元时的最大值
		for(int j=n;j>=v[i];j--){ // f[i]=max(f[i],f[i-v[j]]+v[j]*w[j])
			if(q[i]) continue;
			f[j] = max(f[j], f[j-v[i]]+v[i]*w[i]);
			if(e[i].size()>=1){
				int id1=e[i][0];
				if(j>=v[i]+v[id1]) f[j] = max(f[j], f[j-v[i]-v[id1]]+v[i]*w[i]+v[id1]*w[id1]);
			}
			if(e[i].size()>=2){
				int id1=e[i][0], id2=e[i][1];
				if(j>=v[i]+v[id2]) f[j] = max(f[j], f[j-v[i]-v[id2]]+v[i]*w[i]+v[id2]*w[id2]);
				if(j>=v[i]+v[id1]+v[id2]) f[j] = max(f[j], f[j-v[i]-v[id1]-v[id2]]+w[i]*v[i]+w[id1]*v[id1]+w[id2]*v[id2]);
			}
			ans=max(ans,f[j]);
		}
	}
	cout<<ans;
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