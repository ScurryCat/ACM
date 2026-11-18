#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 3e6+9, M = 2e5+9, mod = 998244353; int t_ = 1;
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

string s;
int cnt[N], idx;
struct node{
	int s[62];
}trie[N];

inline int find(char ch){
	if(ch <= '9') return ch - '0';
	if(ch <= 'Z') return ch - 'A' + 10;
	if(ch <= 'z') return ch - 'a' + 36;
}

inline void insert(string &s){
	int p = 0;
	for(char ch : s){
		if(!trie[p].s[find(ch)]) trie[p].s[find(ch)] = ++idx;
		p = trie[p].s[find(ch)];
		cnt[p]++;
	}
}

inline int query(string &s){
	int p = 0;
	for(char ch : s){
		if(!trie[p].s[find(ch)]) return 0;
		p = trie[p].s[find(ch)];
	}
	return cnt[p];
}

inline void qwq_(){
	for(int i=0;i<=idx;i++){
		memset(trie[i].s, 0, sizeof trie[i].s);
		cnt[i] = 0;
	}
	idx = 0;
	int n,q;
	cin>>n>>q;
	while(n--){
		cin>>s;
		insert(s);
	}
	while(q--){
		cin>>s;
		cout<<query(s)<<'\n';
	}
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