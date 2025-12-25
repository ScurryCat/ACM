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

// int a[14],b[14];
// int a1,a2,a3,b1,b2,b3;

// inline void qwq_(){
// 	double vic,de,p;
// 	for(int i=0;i<4;i++){
// 		int x; cin>>x;
// 		a[x]++;
// 	}
// 	for(int i=0;i<4;i++){
// 		int x; cin>>x;
// 		b[x]++;
// 	}
// 	for(int i=1;i<=13;i++){
// 		if(a[i]>3) a1=1;
// 		if(a[i]>2) a2=1;
// 		if(a[i]==2) a3++;
// 		if(b[i]>3) b1=1;
// 		if(b[i]>2) b2=1;
// 		if(b[i]==2) b3++;
// 	}
// 	if(a1){
// 		if(!b1) cout<<"1/1 0/1 0/1";
// 		else if(b2) cout<<"0/0 1/13 12/13";
// 		else cout<<"0/1 1/1 0/1";
// 	}
// 	else if(a2){
// 		vic=0; de=12.0/13; p=1.0/13;
// 		if(b1) cout<<"0/13 1/13 12/13";
// 		else if(b2) cout<<"23/169 123/169 23/169";
// 		else if(b3==2) cout<<"24/169 123/169 22/169";
// 	}
// 	else if(a3==2){
// 		if(b1) cout<<"0/1 0/1 1/1";
// 		else if(b2) cout<<"22/169 123/169 24/169";
// 		else if(b3==2) cout<<"22/169 125/169 22/169";
// 		else cout<<"2/13 11/13 0/13";
// 	}
// 	else{
// 		if(b1 || b2) cout<<"0/1 0/1 1/1";
// 		else if(b3==2) cout<<"0/1 11/13 2/13";
// 		else cout<<"0/1 1/1 0/1";
// 	}
// }

int a[5],b[5];

inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

int win(){
	int a1=0,a2=0,a3=0,b1=0,b2=0,b3=0;
	int cnt1[14]={0}, cnt2[14]={0};
	for(int i=0;i<5;i++) cnt1[a[i]]++;
	for(int i=0;i<5;i++) cnt2[b[i]]++;
	for(int i=1;i<=13;i++){
		if(cnt1[i]>=4) a1=1;
		if(cnt1[i]==3) a2=1;
		if(cnt1[i]==2) a3=1;
		if(cnt2[i]>=4) b1=1;
		if(cnt2[i]==3) b2=1;
		if(cnt2[i]==2) b3=1;
	}
	debug(a[4],b[4],a1,a2,a3,b1,b2,b3);
	if(a1 && b1) return 0;
	if(a1) return 1;
	if(b1) return -1;
	if(a2&&a3 && b2&&b3) return 0;
	if(a2&&a3) return 1;
	if(b2&&b3) return -1;
	return 0;
}

inline void qwq_(){
	int ans1=0, ans2=0, ans3=0;
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	cin>>b[0]>>b[1]>>b[2]>>b[3];
	for(int i=1;i<=13;i++){
		for(int j=1;j<=13;j++){
			a[4]=i; b[4]=j;
			if(win()==1) ans1++;
			else if(win()==0) ans2++;
			else ans3++;
		}
	}
	cout<<ans1/gcd(ans1,169)<<'/'<<169/gcd(ans1,169)<<' '<<ans2/gcd(ans2,169)<<'/'<<169/gcd(ans2,169)<<' '<<ans3/gcd(ans3,169)<<'/'<<169/gcd(ans3,169);
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