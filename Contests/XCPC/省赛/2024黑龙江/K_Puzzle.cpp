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

unordered_set<int> vis;

inline void qwq_(){
	vector<int> a(4);
	cin>>a[0]>>a[1]>>a[2]>>a[3];

	sort(a.begin(), a.end());

	do{
		for(int op1=0; op1<3; op1++){
			for(int op2=0; op2<3; op2++){
				for(int op3=0; op3<3; op3++){
					int op[] = {op1, op2, op3};

					vector<int> stk;
					stk.push_back(a[0]);
					for(int i=0; i<3; i++){
						if(op[i] == 0){
							stk.push_back(a[i+1]);
						}
						if(op[i] == 1){
							stk.push_back(-a[i+1]);
						}
						if(op[i] == 2){
							int x = stk.back();
							stk.pop_back();
							stk.push_back(x * a[i+1]);
						}
					}
					while(stk.size()>1){
						int x = stk.back();
						stk.pop_back();
						int y = stk.back();
						stk.pop_back();
						stk.push_back(x + y);
					}
					
					vis.insert(stk.back());
				}
			}
		}
	}while(next_permutation(a.begin(),a.end()));

	cout<<vis.size();
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