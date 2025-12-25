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

// 1 1 3 4 2
// 3 1 3 4 2

// inline void qwq_(){
// 	int n; cin>>n;
// 	priority_queue<int> a,b;
// 	int cnt=0;
// 	for(int i=1;i<=n;i++){
// 		int x; cin>>x;
// 		if(x&1) a.push(x);
// 		else b.push(x);
// 	}
// 	if(a.size()==0){
// 		for(int i=1;i<=n;i++) cout<<"0 ";
// 		cout<<'\n';
// 	}
// 	else{
// 		cnt+=a.top();
// 		a.pop();
// 		while(b.size()){
// 			cout<<cnt<<' ';
// 			cnt+=b.top();
// 			b.pop();
// 		}
// 		while(a.size()){
// 			cout<<cnt<<' ';
// 			cnt+=a.top();
// 			a.pop();
// 			if(cnt%2==0) cnt=0;
// 		}
// 		cout<<cnt<<' ';
// 		cout<<'\n';
// 	}
// }

// 3 7 9
// 3 7 9 0 1 0 1
// 1 0 3 7 9 0 1
// 1 0 1 0 3 7 9
// 3 7 9 7 9 7 9

int orz,eee;

inline bool check(int i,int x){
	if(x<0) return 0;
	int q=i-1-x, p=orz-x;
	int l=max(0,q-p);
	int r=min(q,eee-1);
	if(l>r) return 0;
	if(l%2==0 || l<r) return 1;
	return 0;
}

inline void qwq_(){
	int n; cin>>n;
	vector<ll> odd,even;
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		if(x&1) even.push_back(x);
		else odd.push_back(x);
	}
	eee=even.size();
	orz=odd.size();
	sort(even.begin(),even.end(),greater<int>());
	sort(odd.begin(),odd.end(),greater<int>());
	if(even.empty()){
		for(int i=1;i<=n;i++) cout<<"0 ";
		cout<<'\n';
	}
	else{
		vector<ll> s(odd.size()+1);
		ll ans;
		for(int i=1;i<=odd.size();i++) s[i]=s[i-1]+odd[i-1];
		for(int i=1;i<=n;i++){
			int x=min(i-1,(int)odd.size());
			// q=i-1-x, odd.size()-x
			if(check(i,x)) ans=s[x]+even[0];
			else if(check(i,x-1)) ans=s[x-1]+even[0];
			else ans=0;
			cout<<ans<<' ';
		}
		cout<<'\n';
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