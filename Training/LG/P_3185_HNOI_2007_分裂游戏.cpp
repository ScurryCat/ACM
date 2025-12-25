#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e2+9, M = 1e4+9, mod = 998244353; int t_ = 1;
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

vector<int> sg(21);

inline void qwq_(){
	int n; cin>>n;
	int eor =0;
	vector<int> a(n);
	for(int i=n-1;~i;i--){
		cin>>a[i];
		if(a[i]&1) eor^=sg[i];
	}
	int x=-1,y=-1,z=-1,cnt=0;
	if(eor==0){
		cout<<x<<' '<<y<<' '<<z<<'\n';
		cout<<cnt<<'\n';
		return;
	}
	for(int i=n-1;i;i--){
		if(!a[i]) continue;
		for(int j=i-1;~j;j--){
			for(int k=j;~k;k--){
				if((eor^sg[i]^sg[j]^sg[k])==0){
					// cout<<eor<<' '<<sg[i]<<' '<<sg[j]<<' '<<sg[k]<<'\n';
					if(x==-1) x=i,y=j,z=k;
					cnt++;
				}
			}
		}
	}
	cout<<n-x-1<<' '<<n-y-1<<' '<<n-z-1<<'\n';
	cout<<cnt<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for(int i=1;i<21;i++){
		vector<int> ap(100);
		for(int j=0;j<i;j++){
			for(int k=0;k<=j;k++){
				ap[sg[j]^sg[k]]=1;
			}
		}
		for(int j=0;j<100;j++){
			if(!ap[j]){
				sg[i]=j;
				break;
			}
		}
	}
	// for(int i=0;i<21;i++) cout<<sg[i]<<' ';cout<<'\n';

	int yyy = 1;
	cin >> yyy;
	while(yyy--){
		qwq_();
		t_+=1;
	}
	return 0;
}