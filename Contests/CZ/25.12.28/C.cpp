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

inline void qwq_(){
	int n; cin >> n;
  vector<int> a(n+1), f(n+1);
  for(int i=1; i<n; i++) cin >> a[i];
  unordered_map<int, vector<int>> mp;
  int ans = 0;

  f[1] = 1;
  for(int i=2; i<n; i++){
    if(a[i] == a[i-1]+1) f[i] = f[i-1]+1; 
    else f[i] = 1, mp[f[i-1]].push_back(i-f[i-1]);
    if(i+1 == n) mp[f[i]].push_back(i-f[i]+1);
  }

  // for(auto x : mp){
  //   cout << x.first << ':';
  //   for(auto y : x.second) cout << y << ' '; cout << '\n';
  // }

  for(auto it : mp){
    int mx = it.first;
    for(auto x : mp[mx]){
      if(a[x] > 1){
        int y = a[x] - 1;
        if(a[x-1]+1 == y) ans = max(ans, f[x-1]+f[x+mx-1]+1);
        ans = max(ans, f[x+mx-1]+1);
      }
      if(a[x+mx-1] < n){
        int y = a[x+mx-1] + 1;
        int i = x + mx;
        while(f[i] < f[i+1]) i++;
        if(a[x+mx]-1 == y) ans = max(ans, f[i]+f[x+mx-1]+1);
        ans = max(ans, f[x+mx-1]+1);
      }
      ans = max(ans, f[x+mx-1]);
    }
  }
  if(n==2) ans = 2;
  cout << ans << '\n';
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