#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e6+9, M = 2e5+9, mod = 998244353; int t_ = 1;
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

int n, res;
int pre[N], suf[N];
pair<int, int> d[N];

// a[i]-i <= a[j]-j && i-b[i] <= j-b[j]
// a[i]-i >= a[j]-j && i-b[i] >= j-b[j]
// d[i].first <= d[j].first && d[i].second >= d[j].second

inline bool cmp(pair<int, int> x, pair<int, int> y){
	if(x.first != y.first) return x.first < y.first;
	return x.second < y.second;
}

inline void qwq_(){
	cin >> n;
	for(int i=1;i<=n;i++){
		int a, b;
		cin >> a >> b;
		d[i].first = a - i;
		d[i].second = i - b;
	}
	
	sort(d+1, d+n+1, cmp);

	pre[1] = d[1].second;
	for(int i=2;i<=n;i++){
		pre[i] = min(pre[i-1], d[i].second);
	}

	suf[n] = d[n].second;
	for(int i=n-1;i>=1;i--){
		suf[i] = max(suf[i+1], d[i].second);
	}

	res = 1;
	for(int i=1;i<n;i++){
		if(d[i].first < d[i+1].first && pre[i] > suf[i+1]){
			res++;
		}
	}

	cout << res << '\n';
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