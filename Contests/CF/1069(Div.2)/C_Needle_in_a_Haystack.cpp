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

inline void qwq_(){
	string s,t,ans; cin>>s>>t;
	vector<int> cnt1(26),cnt2(26),pos(26);
	for(int i=0;i<s.size();i++){
		cnt1[s[i]-'a']++;
		pos[s[i]-'a']=i;
	}
	for(int i=0;i<t.size();i++) cnt2[t[i]-'a']++;
	for(int i=0;i<26;i++) if(cnt2[i]<cnt1[i]){
		cout<<"Impossible\n";
		return;
	}
	for(char ch : s){
    for(int i=0;i<ch-'a';i++){
      while(cnt2[i]>cnt1[i]){
        ans.push_back(i+'a');
        cnt2[i]--;
      }
    }
    ans.push_back(ch);
  }
  for(int i=0;i<26;i++){
    while(cnt2[i]>cnt1[i]){
      ans.push_back(i+'a');
      cnt2[i]--;
    }
  }
	cout<<ans<<'\n';
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