#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {os << "["; for(int i=0; i<v.size(); i++) os << (i?", ":"") << v[i]; return os << "]";}
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {return os << "(" << p.first << ", " << p.second << ")";}
void debug_out(vector<string> names, int idx) { cerr << endl;}
template <typename Head, typename... Tail>
void debug_out(vector<string> names, int idx, Head H, Tail... T) {if (idx > 0) cerr << ", ";string name = names[idx]; name.erase(0, name.find_first_not_of(' ')); name.erase(name.find_last_not_of(' ') + 1);cerr << name << "=" << H;debug_out(names, idx + 1, T...);}
#define debug(...) { \
	string _s = #__VA_ARGS__, _tmp; vector<string> _names; int _p = 0; \
	for (char c : _s) { \
		if (c == '(' || c == '{') _p++; \
		else if (c == ')' || c == '}') _p--; \
		else if (c == ',' && _p == 0) { _names.push_back(_tmp); _tmp = ""; continue;} \
		_tmp += c; \
	} _names.push_back(_tmp); \
	cerr << "Line " << __LINE__ << ": "; \
	debug_out(_names, 0, __VA_ARGS__); \
}
#else
#define debug(...) 
#endif

using ll = long long;

void qwq_(){

}

int main(){
  #ifdef LOCAL
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif

  int t=1;
  // cin>>t;
  while(t--) qwq_();
  return 0;
}