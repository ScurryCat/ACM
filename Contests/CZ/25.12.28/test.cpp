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

inline ll gcd(ll a, ll b){
  return b ? gcd(b,a%b) : a;
}

inline ll lcm(ll a, ll b){
  return a * b / gcd(a, b);
}

inline ll qwq_(ll a, ll b){
  ll ans = ((a + gcd(a, b)) * (b + gcd(a, b))) / (gcd(a, b) * gcd(a, b));
  // cout << ans << '\n';
  return ans;
}

inline ll check(ll a, ll b){
  ll ans = 1e9;
  for(ll i=1;i<=10000;i++){
    ans = min(ans, lcm(a+i, b+i) / (gcd(a+i, b+i)));
  }
  return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

  srand(time(0));
	int t = 1e6, n = 1000;
	while(t--){
    ll a=rand()%n+1, b=rand()%n+1;
		if(qwq_(a, b) != check(a, b)){
      cout<<qwq_(a, b)<<' '<<check(a, b)<<' ';
      cout<<a<<' '<<b<<'\n';
      break;
    }
		t_+=1;
	}
	return 0;
}